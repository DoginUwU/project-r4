//
// Created by doginuwu on 6/15/24.
//
#include "decryptor-dialog.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include "consts.hpp"

void DecyptorDialog::decryptor_dialog(const Path& path)
{
    if(std::filesystem::exists(path.location + path.dialogs_output_location))
    {
        if(!std::filesystem::is_directory(path.location + path.dialogs_output_location))
        {
            std::cerr << "[DIALOG] Output path is not a directory" << std::endl;
        }

        for (const auto& entry : std::filesystem::directory_iterator(path.location + path.dialogs_output_location))
        {
            std::filesystem::remove(entry.path());
        }
    } else
    {
        if(!std::filesystem::create_directory(path.location + path.dialogs_output_location))
        {
            std::cerr << "[DIALOG] Failed to create output directory" << std::endl;
        }
    }

    for (const auto& entry : std::filesystem::directory_iterator(path.location + path.bin_output_location))
    {
        std::string file_path = entry.path();
        create_dialog_file(path, file_path);
    }
}

void DecyptorDialog::create_dialog_file(const Path& path, const std::string file_path)
{
    std::cout << "[DIALOG] Decrypting " << file_path << std::endl;

    std::ifstream file(file_path, std::ios::binary);

    if(!file.is_open())
    {
        std::cerr << "[DIALOG] Failed to open file" << std::endl;
    }

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(file), {});

    file.close();

    std::string interpretedText;

    for (int i = 0; i < buffer.size(); i += 2)
    {
        // convert little endian to big endian
        uint16_t value = (buffer[i] << 8) | buffer[i + 1];

        if (Consts::dialogMap.contains(value))
        {
            interpretedText += Consts::dialogMap.at(value);
        } else
        {
            interpretedText += '?';
        }
    }

    std::string output_path_name = file_path.substr(file_path.find_last_of('/') + 1);

    std::ofstream output(path.location + path.dialogs_output_location + "/" + output_path_name + ".txt");
    output << interpretedText;
    output.close();

    std::cout << "[DIALOG] Decrypted " << file_path << std::endl;
}
