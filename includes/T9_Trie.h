//
// Created by Mateusz Miliutin on 04/02/2026.
//

#ifndef T9_T9_TRIE_H
#define T9_T9_TRIE_H
#include <cassert>
#include <list>
#include <string>


#include "Nodes.h"
// #include <iostream>



class T9_Trie {
private:
    Node* root;
public:
    T9_Trie() {
        root = new MapNode("", 0);
    }
    ~T9_Trie();

    // [[nodiscard]] Node* getRoot() const { return root; }
    [[nodiscard]] bool wordExists(const std::string& word) const {
        return (getWordNode(this->root, word) != nullptr);
    }

    void addWord(const std::string& word) const { addWord(this->root, word); }
    static void addWord(Node* node, const std::string& word);

    [[nodiscard]] Node* getWordNode(const std::string& word) const { return getWordNode(root, word); }
    static Node* getWordNode(Node* node, const std::string &word);

};


#endif //T9_T9_TRIE_H