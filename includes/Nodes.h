//
// Created by Mateusz Miliutin on 04/02/2026.
//

#ifndef T9_NODES_H
#define T9_NODES_H

#include <iostream>

struct Node {
    int type = 0;
    std::string value;

    Node(std::string value, const int type) {
        this->type = type;
        this->value = std::move(value);
    }

    virtual ~Node() = default;

    virtual Node* addChild(const std::string& word, int mode) = 0;
    virtual Node* findChild(const std::string& word) = 0;

    virtual void listChildren() const = 0;
    void display() const {
        std::cout << "==================================" << std::endl;
        std::cout << "Testing node (" << this << "): \n> type: " << this->type <<"\n> value: \"" << this->value << "\"" << std::endl;
        std::cout << "Pointers to children: " << std::endl;
        listChildren();
        std::cout << "==================================" << std::endl;

    }
};



struct MapNode final : Node {
    std::unordered_map<std::string, MapNode*> children;

    explicit MapNode(const std::string& word, int mode=0) : Node(word, mode) {}
    ~MapNode() override;

    Node* findChild(const std::string &word) override;
    Node* addChild(const std::string& word, const int mode) override;

    void listChildren() const override;
};


constexpr int ALPHABET = 26;
struct ArrayNode final : Node {
    int children_counter = 0;
    ArrayNode* children[ALPHABET]{};

    explicit ArrayNode(const std::string& word, int mode=0) : Node(word, mode) {}
    ~ArrayNode() override;

    Node* findChild(const std::string& word) override;
    Node* addChild(const std::string& word, const int mode) override;

    void listChildren() const override;
};

#endif //T9_NODES_H