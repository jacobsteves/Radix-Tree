# Radix Trie
A Radix Trie, sometimes just called a Trie, a digital tree, or a prefix tree, is a tree-shaped
deterministic finite automaton (DFA). It is a kind of serach trie that is used to store
a dynamic set or associative array where keys are usually strings. Unlike a binary search,
there is no node in the tree associated with a specific key. Instead, it acts more like a
state machine, where your current value is where you are located within the state.


In the determination of finite languages, Tries are much more efficient than looping through
every piece of language. In english, for example, there are millions of words. However, only 26
letters. Every word has to start with a letter. So instead of making a million comparisons to
see if the word matches a languages, we can make at most 26 comparisons to the first letter,
and then to the second letter, and then the third.


In this example, we store the letters within a hash so there is constant lookup time. Therefore,
the maximum amount of time it takes to match a letter to the language takes just n iterations, where
n is the length of the string.

## Getting Started
- Run `make` in the directory to create your binary file.
- Run the program.

## Input
Look at `examples/default.in` and `examples/custom.in` for examples.
- The first bit of input the program takes is the state type (CUSTOM, or DEFAULT)
     - `DEFAULT` will test your input on the default language, which happens to be simple [MIPS instructions](https://en.wikipedia.org/wiki/MIPS_architecture).
     - `CUSTOM` will allow you to type in your own language. It will read words until you type `END`
- The second type of input the program takes is language testing. You type anything, and the program determines if it is part of the specified language.

## Time Complexity
Time complexity depends entirely on the implementation.


When using hashes:
- word lookup typically is `O(n)` where n is the length of the word
- insert is typically `O(n log n)` where n is the length of the word but the complexity depends on the type of hash being used.

When using Binary Trees:
- word lookup is typically `O(n)`
- insert depends entirely on the implementation, but can be as fast as `O(n log m )` where m is the number of keys in the tree.

## Comparisons
### Advantages over Hash Tables
- Looking up data in a trie is typically faster than a hash table
- There are no collisions of different keys in a trie
- There is no need to provide a hash function or to change hash functions as more keys are added
- A tree can provide alphabetical ordering of entries by key

### Drawbacks over Hash Tables
- Tries can be slower in some cases for lookup if the data is accessed on a Hard Disk Drive or some other type of secondary storage where Random-Access time is high compared to Main Memory
- Some keys (like floats) can lead to long chains that are not particularly meaningful
- Can often require more space than a hash table, as memory is allocated for each character in the search string rather than a single chunk of memory as in hash tables
