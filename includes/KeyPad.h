//
// Created by Mateusz Miliutin on 07/02/2026.
//

#ifndef T9_KEYPAD_H
#define T9_KEYPAD_H

#include <unordered_set>
#include <ranges>
#include <iostream>


class KeyPad {
    std::unordered_map<char, std::unordered_set<char>> buttons;
    size_t max_values = 0;
    std::string keys_list;

    std::string strKeysRow(const std::string &keys);

public:

    std::unordered_set<char> getValues(char key);
    void addButton(char key, const std::unordered_set<char>& values);

    std::string strKeypad();
};


#endif //T9_KEYPAD_H