//
// Created by doginuwu on 6/15/24.
//
#include "encryptor-dialog.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <vector>

#include "consts.hpp"

void EncryptorDialog::encryptor_dialog(const Path& path)
{
    if(std::filesystem::exists(path.location + path.encrypted_dialogs_output_location))
    {
        if(!std::filesystem::is_directory(path.location + path.encrypted_dialogs_output_location))
        {
            std::cerr << "[DIALOG] Output path is not a directory" << std::endl;
        }

        for (const auto& entry : std::filesystem::directory_iterator(path.location + path.encrypted_dialogs_output_location))
        {
            std::filesystem::remove(entry.path());
        }
    } else
    {
        if(!std::filesystem::create_directory(path.location + path.encrypted_dialogs_output_location))
        {
            std::cerr << "[DIALOG] Failed to create output directory" << std::endl;
        }
    }

    for (const auto& entry : std::filesystem::directory_iterator(path.location + path.dialogs_output_location))
    {
        std::string file_path = entry.path();
        create_bin_file(path, file_path);
    }
}

void EncryptorDialog::create_bin_file(const Path& path, const std::string file_path)
{
    std::cout << "[DIALOG] Encrypting " << file_path << std::endl;

    std::ifstream file(file_path);

    std::string textContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    auto reversedDialogMap = Consts::reverse_dialog_map();

    std::string output_path_name = file_path.substr(file_path.find_last_of('/') + 1);
    output_path_name = std::regex_replace(output_path_name, std::regex(".bin.txt"), "");
    output_path_name = output_path_name + ".bin";
    std::ofstream outputFile(path.location + path.encrypted_dialogs_output_location + "/" + output_path_name, std::ios::binary);

    // need to open the binary file and place in the correct position
    std::ifstream originalBinFile(path.location + path.bin_output_location  + "/" + output_path_name, std::ios::binary);

    if(!originalBinFile.is_open())
    {
        std::cerr << "[DIALOG] Failed to open file" << std::endl;
    }

    std::vector<uint16_t> originalData(std::istreambuf_iterator<char>(originalBinFile), {});

    size_t index = 0;
    for (char c: textContent)
    {
        index++;
        std::string str(1, c);
        if (reversedDialogMap.contains(str))
        {
            uint16_t encodedValue = reversedDialogMap.at(str);

            // convert big endian to little endian
            encodedValue = ((encodedValue & 0xFF) << 8) | ((encodedValue & 0xFF00) >> 8);

            outputFile.write(reinterpret_cast<const char*>(&encodedValue), sizeof(encodedValue));
        } else
        {
            uint16_t encodedValue = originalData[index];
            outputFile.write(reinterpret_cast<const char*>(&encodedValue), sizeof(encodedValue));
        }
    }

    outputFile.close();

    std::cout << "[DIALOG] Encrypted " << file_path << std::endl;
}
