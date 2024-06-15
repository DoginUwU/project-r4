//
// Created by doginuwu on 6/15/24.
//
#include "decryptor-bin.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

void DecryptorBin::decryptor_bin(const Path& path)
{
    if(std::filesystem::exists(path.location + path.bin_output_location))
    {
        if(!std::filesystem::is_directory(path.location + path.bin_output_location))
        {
            std::cerr << "[BIN] Output path is not a directory" << std::endl;
        }

        for (const auto& entry : std::filesystem::directory_iterator(path.location + path.bin_output_location))
        {
            std::filesystem::remove(entry.path());
        }
    } else
    {
        if(!std::filesystem::create_directory(path.location + path.bin_output_location))
        {
            std::cerr << "[BIN] Failed to create output directory" << std::endl;
        }
    }

    std::string bin_path = path.location + "/R4.BIN";

    std::cout << "[BIN] Decrypting " << bin_path << std::endl;
    std::ifstream file(bin_path, std::ios::binary);

    if(!file.is_open())
    {
        std::cerr << "[BIN] Failed to open file" << std::endl;
    }

    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));

    if(file.fail())
    {
        std::cerr << "[BIN] Failed to read file" << std::endl;
    }

    std::vector<int> positions(count + 1);
    for (int i = 0; i <= count; i++)
    {
        int position;
        file.read(reinterpret_cast<char*>(&position), sizeof(position));

        if(file.fail())
        {
            std::cerr << "[BIN] Failed to read position chunk" << std::endl;
        }

        positions[i] = position * 2048;
    }

    for (int i = 0; i < count; i++)
    {
        if(!is_count_a_dialog(i)) continue;

        int pos1 = positions[i];
        int pos2 = positions[i + 1];
        int len = pos2 - pos1;

        file.seekg(pos1, std::ios::beg);

        if(file.fail())
        {
            std::cerr << "[BIN] Failed to seek into file" << std::endl;
        }

        std::vector<char> buffer(len);
        file.read(buffer.data(), len);

        if(file.fail())
        {
            std::cerr << "[BIN] Failed to read a segment into file" << std::endl;
        }

        std::ofstream output(path.location + path.bin_output_location + "/" + std::to_string(i) + ".bin", std::ios::binary);

        if(!output)
        {
            std::cerr << "[BIN] Failed to open output file" << std::endl;
        }

        output.write(buffer.data(), len);
    }

    file.close();

    std::cout << "[BIN] Decrypted in " << path.location + path.bin_output_location << std::endl;
}
