CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -g
EXEC = Trie
OBJECTS = trie.o main.o

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

trie.o: trie.cc trie.h

main.o: main.cc

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC}
