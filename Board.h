//
// Created by AndrewGapic on 2017-01-18.
//

#ifndef BOGGLE_SOLVER_BOARD_H
#define BOGGLE_SOLVER_BOARD_H

#include <vector>
using namespace std;

class Board {
public:
    Board(int size, vector <vector<char> > letters);
    const int getSize();

    const vector <vector<char> > getLetters();
private:
    int size_;
    vector <vector<char> > letters_;
};


#endif //BOGGLE_SOLVER_BOARD_H
