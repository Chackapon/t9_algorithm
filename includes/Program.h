//
// Created by Mateusz Miliutin on 07/02/2026.
//

#ifndef T9_PROGRAM_H
#define T9_PROGRAM_H

// #include <iostream>
#include <string>

#include "T9_Trie.h"
#include "KeyPad.h"




class Program {
    T9_Trie *trie;

    std::unordered_set<std::string> previous_searches;
    std::unordered_set<std::string> filterForRealWords(const std::unordered_set<std::string> &candidates) const;
    std::unordered_set<std::string> filterForCandidates(const std::unordered_set<std::string>& word_chunks) const;

public:
    KeyPad keypad;

    Program() {
        trie = new T9_Trie();
        clearSearch();
    }
    ~Program() { delete this->trie; }

    void loadWordFile(const std::string& fileName) const;
    void loadKeysFiles(const std::string& fileName);

    void clearSearch() { previous_searches = {""}; }
    std::list<std::string> search(char key);

};

#endif //T9_PROGRAM_H