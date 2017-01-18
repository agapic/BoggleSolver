//
// Created by AndrewGapic on 2017-01-16.
//

#include "TrieNode.h"

TrieNode::TrieNode() {
    words_ = false;
    for(int i = 0; i < 26; i++) {
        next_[i] = nullptr;
    }
}