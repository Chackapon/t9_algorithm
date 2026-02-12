//
// Created by Mateusz Miliutin on 07/02/2026.
//
#include "Program.h"

#include <fstream>

std::unordered_set<std::string> crossProduct( std::unordered_set<std::string> word_chunks, std::unordered_set<char> button_values ) {
    std::unordered_set<std::string> result;
    for (const auto& element_a : word_chunks) {
        for (const auto element_b : button_values) {
            result.insert(element_a + element_b);
        }
    }
    return result;
}

std::list <std::string> Program::search(char key) {

    std::unordered_set<std::string> letter_combos = crossProduct(this->previous_searches, this->keypad.getValues(key));
    const auto candidates = filterForCandidates(letter_combos);
    this->previous_searches = candidates;


    const auto real_words = filterForRealWords(candidates);
    std::list<std::string> result;
    for (const auto& e: real_words) {
        result.push_back(e);
    }

    return result;
}

// TODO: make it a filter function
std::unordered_set<std::string> Program::filterForCandidates(const std::unordered_set<std::string>& word_chunks) const {
    std::unordered_set<std::string> word_candidates;
    for (const auto& e : word_chunks) {
        if (this->trie->wordExists(e)) {
            word_candidates.insert(e);
        }
    }
    return word_candidates;
}

// TODO: make it a filter function
std::unordered_set<std::string> Program::filterForRealWords(const std::unordered_set<std::string> &candidates) const {
    std::unordered_set<std::string> results;
    for (const auto& e : candidates) {
        if (this->trie->getWordNode(e)->type == 1) results.insert(e);
    }
    return results;
}



// TEXT FILE HANDLING
//=============================================================
void Program::loadWordFile(const std::string &fileName) const {
    std::fstream file( fileName );
    if (!file.is_open()) {
        std::cerr << "Could not open words file" << std::endl;
        exit(1);
    }

    std::string word;
    while (!file.eof()) {
        file >> word;
        trie->addWord(word);
    }
}
void Program::loadKeysFiles(const std::string &fileName) {
    std::fstream file( fileName );
    if (!file.is_open()) {
        std::cerr << "Could not open keys file" << std::endl;
        exit(1);
    }

    std::string line;
    std::unordered_set<char> key_values;

    while (!file.eof()) {
        getline(file, line);
        key_values.clear();


        if (line.length() > 2) for (auto value : line.substr(2, line.length())) { key_values.insert(value); }

        this->keypad.addButton(line[0], key_values);
    }
}
//=============================================================
