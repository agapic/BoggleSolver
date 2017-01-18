//
// Created by AndrewGapic on 2017-01-16.
//

#ifndef BOGGLE_SOLVER_TRIENODE_H
#define BOGGLE_SOLVER_TRIENODE_H

#include <memory>
#include <string>
#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode();
    bool words_;
    shared_ptr<TrieNode> next_[26];
};

#endif //BOGGLE_SOLVER_TRIENODE_H
