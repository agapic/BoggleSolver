//
// Created by AndrewGapic on 2017-01-18.
//

#include "Board.h"
#include <stdexcept>
Board::Board(int size, vector <vector<char> > letters) : size_(size), letters_(letters) {
    for (auto &i : letters) {
        if (i.size() != size) {
            throw std::invalid_argument("Board size doesn't match size in the provided board.");
        }
    }


}

const int Board::getSize() {
    return size_;
}

const vector <vector<char> > Board::getLetters() {
    return letters_;
}