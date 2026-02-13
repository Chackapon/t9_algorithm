//
// Created by Mateusz Miliutin on 05/02/2026.
//

// #include <unordered_map>
// #include <unordered_set>
#include <iostream>
#include "../includes/Nodes.h"


MapNode::~MapNode() {
    for (const auto &child : this->children) {
        delete child.second;
    }
}



Node *MapNode::findChild(const char word) {
    const auto it = children.find(word);
    if (it == children.end()) return nullptr;
    return it->second;
}
Node *MapNode::addChild(const char word, const int mode) {
    auto new_node = new MapNode(word, mode);
    this->children.insert({word, new_node});
    return new_node;
}



void MapNode::listChildren() const {
    for (const auto& child : this->children) {
        std::cout << child.second << "=" << child.first << std::endl;
    }
}
