#include <iostream>
#include "trie.h"

/**
 * To give a Trie example, we construct the language that it identifies.
 *
 * Follow the format within `examples/custom.in` and `examples/default.in`.
 * By default, the Trie's language is MIPS commands. However, you can specify your
 * custom language to detect.
 *
 * The system will then output if your input matches the specified language or not.
 * @return
 */

 /**
  * This method creates Trie commands based on MIPS commands.
  * This is just used as an example.
  * @param trie to add commands to
  */
void createTrieCommands(Trie &trie) {
    trie.addCommand(".word");
    trie.addCommand("jr");
    trie.addCommand("jalr");
    trie.addCommand("beq");
    trie.addCommand("bne");
    trie.addCommand("add");
    trie.addCommand("sub");
    trie.addCommand("slt");
    trie.addCommand("sltu");
    trie.addCommand("lis");
    trie.addCommand("mflo");
    trie.addCommand("mfhi");
    trie.addCommand("mult");
    trie.addCommand("multu");
    trie.addCommand("div");
    trie.addCommand("divu");
    trie.addCommand("sw");
    trie.addCommand("lw");
}

int main() {
    std::string line;
    Trie trie;

    getline(std::cin, line);

    if (line == "CUSTOM") {
        while(getline(std::cin, line)) {
            if (line == "END") break;
            trie.addCommand(line);
        }
    } else {
        createTrieCommands(trie);
    }

    while(getline(std::cin, line)) {
        std::string validity = (trie.validCommand(line)) ? "is valid." : "is not valid.";
        std::cout << line << " " << validity << std::endl;
    }

    return 0;
}
