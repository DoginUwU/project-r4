//
// Created by doginuwu on 6/15/24.
//
#ifndef DECRYPTOR_BIN_HPP
#define DECRYPTOR_BIN_HPP
#include "path.hpp"

class DecryptorBin
{
public:
    static void decryptor_bin(const Path& path);

private:
    static bool is_count_a_dialog(const int count)
    {
        if(count >= 678 && count <= 685) return true;
        if(count >= 687 && count <= 694) return true;
        if(count >= 696 && count <= 703) return true;
        if(count >= 705 && count <= 712) return true;
        if(count == 723) return true;
        if(count >= 726 && count <= 728) return true;

        return false;
    }
};
#endif //DECRYPTOR_BIN_HPP
