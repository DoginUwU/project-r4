//
// Created by doginuwu on 6/15/24.
//
#ifndef DECRYPTOR_DIALOG_H
#define DECRYPTOR_DIALOG_H
#include <string>

#include "path.hpp"

class DecyptorDialog
{
public:
    static void decryptor_dialog(const Path& path);

private:
    static void create_dialog_file(const Path& path, const std::string file_path);
};
#endif //DECRYPTOR_DIALOG_H
