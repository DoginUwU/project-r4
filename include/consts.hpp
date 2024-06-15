//
// Created by doginuwu on 6/15/24.
//
#ifndef CONSTS_HPP
#define CONSTS_HPP
#include <string>
#include <unordered_map>

class Consts {
public:
    static inline const std::unordered_map<u_int16_t, std::string> dialogMap = {
        {0x0000, " "}, {0x0100, ","}, {0x0200, "."}, {0x0300, ":"}, {0x0400, ";"},
        {0x0500, "?"}, {0x0600, "!"}, {0x0700, "±"}, {0x0800, "º"}, {0x0900, "/"},
        {0x0A00, "'"}, {0x0B00, "'"}, {0x0C00, "\""}, {0x0D00, "("}, {0x0E00, ")"},
        {0x0F00, "["}, {0x1000, "]"}, {0x1100, "+"}, {0x1200, "-"}, {0x1300, "="},
        {0x1400, "<"}, {0x1500, ">"}, {0x1600, "¥"}, {0x1700, "$"}, {0x1800, "%"},
        {0x1900, "#"}, {0x1A00, "&"}, {0x1B00, "*"}, {0x1C00, "@"}, {0x1D00, "0"},
        {0x1E00, "1"}, {0x1F00, "2"}, {0x2000, "3"}, {0x2100, "4"}, {0x2200, "5"},
        {0x2300, "6"}, {0x2400, "7"}, {0x2500, "8"}, {0x2600, "9"}, {0x2700, "A"},
        {0x2800, "B"}, {0x2900, "C"}, {0x2A00, "D"}, {0x2B00, "E"}, {0x2C00, "F"},
        {0x2D00, "G"}, {0x2E00, "H"}, {0x2F00, "I"}, {0x3000, "J"}, {0x3100, "K"},
        {0x3200, "L"}, {0x3300, "M"}, {0x3400, "N"}, {0x3500, "O"}, {0x3600, "P"},
        {0x3700, "Q"}, {0x3800, "R"}, {0x3900, "S"}, {0x3A00, "T"}, {0x3B00, "U"},
        {0x3C00, "V"}, {0x3D00, "W"}, {0x3E00, "X"}, {0x3F00, "Y"}, {0x4000, "Z"},
        {0x4100, "a"}, {0x4200, "b"}, {0x4300, "c"}, {0x4400, "d"}, {0x4500, "e"},
        {0x4600, "f"}, {0x4700, "g"}, {0x4800, "h"}, {0x4900, "i"}, {0x4A00, "j"},
        {0x4B00, "k"}, {0x4C00, "l"}, {0x4D00, "m"}, {0x4E00, "n"}, {0x4F00, "o"},
        {0x5000, "p"}, {0x5100, "q"}, {0x5200, "r"}, {0x5300, "s"}, {0x5400, "t"},
        {0x5500, "u"}, {0x5600, "v"}, {0x5700, "w"}, {0x5800, "x"}, {0x5900, "y"},
        {0x5A00, "z"}, {0x5B00, "~"}, {0x5C00, "~"}, {0x5D00, "~"}, {0x5E00, "~"},
        {0x5F00, "~"}, {0x6000, "~"}, {0x0010, "[JUMP]"},
        {0x0560, "[LEN]"}, {0x1440, "[MED]"}, {0x2840, "[RAP]"}
    };
    static std::unordered_map<std::string, u_int16_t> reverse_dialog_map()
    {
        std::unordered_map<std::string, u_int16_t> reversedDialogMap;
        for (const auto& [key, value] : dialogMap) {
            reversedDialogMap[value] = key;
        }

        return reversedDialogMap;
    }
};
#endif //CONSTS_HPP
