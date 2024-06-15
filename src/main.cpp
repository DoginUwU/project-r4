//
// Created by doginuwu on 6/15/24.
//
#include <encryptor-dialog.hpp>

#include "decryptor-bin.hpp"
#include "decryptor-dialog.hpp"
#include "path.hpp"

int main()
{
    const Path path = {
        .location = "/home/doginuwu/Downloads/R4 - Ridge Racer Type 4 (USA)/R4 - Ridge Racer Type 4 (USA)/files",
        .bin_output_location = "/bins_output",
        .dialogs_output_location = "/dialogs_output",
        .encrypted_dialogs_output_location = "/encrypted_dialogs_output"
    };

    DecryptorBin::decryptor_bin(path);
    DecyptorDialog::decryptor_dialog(path);
    EncryptorDialog::encryptor_dialog(path);

    return 0;
}
