//
// Created by AndrewGapic on 2017-01-16.
//

#include "Trie.h"

Trie::Trie() : root_(new TrieNode), wordCount_(0){
}

void Trie::insert(string word) {
    for (int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);
        if (!isalpha(word[i])) return;
    }
    shared_ptr<TrieNode> temp = root_;
    for(int i = 0; i < word.size(); i++) {
        if(temp->next_[word[i] - 'a'] == nullptr) {
            shared_ptr<TrieNode> newNode(new TrieNode());
            temp->next_[word[i] - 'a'] = newNode;
        }
        temp = temp->next_[word[i] - 'a'];
    }
    temp->words_ = true;
    wordCount_++;
}

bool Trie::search(string word) {
    shared_ptr<TrieNode> temp = root_;
    for(int i = 0; i < word.size(); i++) {
        if (temp->next_[word[i] - 'a'] == nullptr) return false;
        temp = temp->next_[word[i] - 'a'];
    }
    return temp->words_;
}

bool Trie::startsWith(string prefix) {
    shared_ptr<TrieNode> temp = root_;
    for(int i = 0; i < prefix.size(); i++) {
        temp = temp->next_[prefix[i] - 'a'];
        if (temp == nullptr) return false;
    }
    return true;
}

void Trie::getWordCount() {
    cout << this->wordCount_ << endl;
}