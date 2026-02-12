//
// Created by Mateusz Miliutin on 04/02/2026.
//

#include "T9_Trie.h"

T9_Trie::~T9_Trie() {
    // std::cout << "Activated trie destructor" << std::endl;
    delete root;
}


Node *T9_Trie::getWordNode(Node *node, const std::string &word) {
    auto current_node = node;

    for (int i = 0; i < word.length(); i++) {
        std::string word_chunk = word.substr(0, i + 1);
        current_node = current_node->findChild(word_chunk);

        if (current_node == nullptr) {
            return nullptr;
        }
    }
    return current_node;
}

void T9_Trie::addWord(Node *node, const std::string &word) {
    int node_type = 0;
    auto current_node = node;
    std::string word_chunk;

    for (int i = 0; i < word.length(); i++) {
        if (i == word.length() - 1) node_type = 1;
        word_chunk += static_cast<char>(std::tolower(word.at(i)));


        auto word_chunk_node = current_node->findChild(word_chunk);


        if (word_chunk_node == nullptr) {
            word_chunk_node = current_node->addChild(word_chunk, node_type);
        }
        current_node = word_chunk_node;
    }
}
