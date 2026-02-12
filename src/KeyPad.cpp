//
// Created by Mateusz Miliutin on 07/02/2026.
//

#include "KeyPad.h"

std::unordered_set<char> KeyPad::getValues(const char key) {
    auto it = buttons.find(key);
    if (it == buttons.end()) return {};
    return it->second;
}

void KeyPad::addButton(char key, const std::unordered_set<char> &values) {
    if (max_values < values.size()) max_values = values.size();
    keys_list += key;
    buttons.insert({key, values});
}

// Helping functions for keypad drawing
std::string line(const int l, const int n) {
    std::string result;
    result += "+";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < l; j++) {
            result += "-";
        }
        result += "+";
    }
    result += "\n";
    return result;
}

std::string KeyPad::strKeysRow(const std::string& keys) {
    std::string result;
    for (auto key : keys) {
        result += "|";
        result += key;
        for (int i=1; i < this->max_values; i++) result += " ";
    }
    //std::format("|{}   ", key);
    result += "|\n";


    for (auto key : keys) {
        int pad = 0;
        result += "|";

        auto it = this->buttons.find(key);
        if (it != this->buttons.end() && !it->second.empty()) {
            for (auto value : it->second) {
                result += value;
                pad++;
            }
        }

        for (int i=pad; i < this->max_values; i++) result += " ";

    }
    result += "|\n";
    return result;
}

std::string KeyPad::strKeypad() {
    const int n = static_cast<int>(this->keys_list.size());
    const int keypad_width = round(sqrt(n));
    const int keypad_height = ceil(sqrt(n));
    std::string result;


    std::string keys = this->keys_list;
    for (int i=(int)keys.length(); i < keypad_height*keypad_width; i++) { keys += " "; }


    // line((int)keypad.max_values,keypad_width);
    result += line((int)this->max_values,keypad_width);
    int line_n = 0;

    for (int i = 0; i < keypad_height; i++) {
        // printKeysRow(keypad, keys.substr(line_n * keypad_width, keypad_width));
        // line((int)keypad.max_values,keypad_width);
        result += strKeysRow(keys.substr(line_n * keypad_width, keypad_width));
        result += line((int)this->max_values,keypad_width);
        line_n++;
    }
    return result;
}
//==================================
