#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "trie.h"

std::shared_ptr<Node> Node::updateNodeWithKey(char key, bool endstate) {
    auto firstState = nextStates.find(key);

    if (firstState != nextStates.end()) {
        return firstState->second;
    } else {
        auto new_node = std::make_shared<Node>(key, endstate);
        nextStates[key] = new_node;
        return new_node;
    }
}

Trie::Trie() {}

void Trie::addCommand(std::string command) {
    std::vector<char> letters(command.begin(), command.end());

    if (letters.empty()) return;

    std::shared_ptr<Node> currentNode = updateNodeWithKey(letters.front(), letters.size() > 1);

    for (auto &letter : letters) {
        currentNode = currentNode->updateNodeWithKey(letter, letter == letters.back());
    }
}

bool Node::childExists(char key) {
    return nextStates.find(key) != nextStates.end();
}

bool Trie::validCommand(std::string command) {
    std::vector<char> letters(command.begin(), command.end());

    if (letters.empty() || !childExists(letters.front())) return false;

    std::shared_ptr<Node> currentNode = nextStates[letters.front()];

    for (auto &letter : letters) {
        if (!currentNode->childExists(letter)) return false;
        currentNode = currentNode->nextStates[letter];
    }

    return currentNode->endstate;
}
