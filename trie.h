#ifndef _TRIE_H_
#define _TRIE_H_
#include <map>

class Node {
public:
    char value;
    bool endstate = false;
    std::map<char, std::shared_ptr<Node>> nextStates;
    Node(): value{}, endstate{} {};
    Node(char value, bool endstate): value{value}, endstate{endstate} {}
    std::shared_ptr<Node> updateNodeWithKey(char key, bool endstate);
    bool childExists(char key);
};

class Trie: public Node {
public:
    void addCommand(std::string command);
    bool validCommand(std::string command);
    Trie();
};

#endif
