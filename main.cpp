#include <iostream>
#include <fstream>

#include <unordered_set>
#include <utility>

#include "Program.h"
// #include <ttui/ttui.hpp>

// #include <lib/ttui/ttui.hpp>
// #include


void printInPlace(const std::string& text) {
    std::cout << "\33[2K\r" << text << std::flush;
}

void displayNode(const Node * node) {
    if (node == nullptr) {
        std::cout << "==================================" << std::endl;
        std::cout << "Node doesn't exist" << std::endl;
        std::cout << "==================================" << std::endl;
    }
    else node->display();
    std::cout << std::endl;
}

#ifndef PROGRAM_NAME
#define PROGRAM_NAME "T9"
#endif

int main(const int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "USAGE: ./PROGRAM_NAME <words_file> <keys_file>" << std::endl;
        exit(1);
    }

    const auto program = new Program();
    program->loadWordFile( argv[1] );
    program->loadKeysFiles( argv[2] );
    const std::string keypad_str = program->keypad.strKeypad();

    char answer = '\0';

    std::list<std::string> suggestions = {};
    std::list<std::string>::iterator suggestions_iterator;

    int suggestion_index = 1;
    bool shut_down = false;

    while (true) {
        system("clear");

        std::cout << keypad_str;

        if (suggestions.empty()) {
            std::cout << "No suggestions available" << std::endl;
        } else {
            std::cout << "Suggested word [" << suggestion_index << "/" << suggestions.size() << "]: " << *suggestions_iterator << std::endl;
        }

        std::cout << "> ";
        std::cin >> answer; //2437

        switch (answer) {
            case '*':
                if (!suggestions.empty()) {
                    ++suggestions_iterator;
                    ++suggestion_index;

                    if (suggestions_iterator == suggestions.end()) {
                        suggestions_iterator = suggestions.begin();
                        suggestion_index = 1;
                    }
                }
                break;

            case '#':
                program->clearSearch();
                suggestions.clear();
                suggestion_index = 1;
                break;

            case '0':
                std::cout << "Shutting down..." << std::endl;
                shut_down = true;

            default:
                suggestions = program->search(answer);
                if (!suggestions.empty()) {
                    suggestions_iterator = suggestions.begin();
                    suggestion_index = 1;
                }

        }
        if (shut_down) break;
    }

    delete program;
    return 0;
}
