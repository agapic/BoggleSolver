//
// Created by AndrewGapic on 2017-01-16.
//

#ifndef BOGGLE_SOLVER_TRIE_H
#define BOGGLE_SOLVER_TRIE_H


#include "TrieNode.h"

class Trie {
public:
    Trie();
    void insert(string);
    bool search(string);
    bool startsWith(string);
    void getWordCount();
private:
    shared_ptr<TrieNode> root_;
    int wordCount_;
};

#endif //BOGGLE_SOLVER_TRIE_H
