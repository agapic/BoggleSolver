# super simple makefile
# call it using 'make NAME=name_of_code_file_without_extension'
# (assumes a .cpp extension)
NAME = BoggleSolver


all:
	@echo "Compiling..."
	g++ -o main main.cpp Trie.h Trie.cpp TrieNode.cpp TrieNode.h Board.h Board.cpp -std=c++11

run: all
	@echo "Running..."
	./$(NAME)

