//
// Created by Mateusz Miliutin on 05/02/2026.
//

#include <iostream>
#include "../includes/Nodes.h"

ArrayNode::~ArrayNode() {
    for (int i = 0; i < this->children_counter; i++) {
        delete children[i];
    }
}



Node *ArrayNode::findChild(const std::string &word) {
    for (int i = 0; i < this->children_counter; i++) {
        if (this->children[i]->value == word) return this->children[i];
    }
    return nullptr;
}
Node *ArrayNode::addChild(const std::string &word, const int mode) {
    this->children[ this->children_counter ] = new ArrayNode(word, mode);
    this->children_counter++;
    return children[ this->children_counter - 1 ];
}



void ArrayNode::listChildren() const {
    for (int i = 0; i < this->children_counter; i++) {
        std::cout << children[i] << "=" << children[i]->value << std::endl;
    }
}
