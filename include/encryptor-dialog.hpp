//
// Created by doginuwu on 6/15/24.
//

#ifndef ENCRYPTOR_DIALOG_H
#define ENCRYPTOR_DIALOG_H

#include "path.hpp"

class EncryptorDialog
{
public:
    static void encryptor_dialog(const Path& path);
private:
    static void create_bin_file(const Path& path, const std::string file_path);
};
#endif //ENCRYPTOR_DIALOG_H
