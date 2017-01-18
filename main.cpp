#include <iostream>
#include <fstream>

#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "Trie.h"
#include "Board.h"

using namespace std;


//bool flag = false;
Trie *trie = new Trie();
vector<string> words;
void DFS(Board *b, vector <vector<bool> > visited, int i, int j, string &str) {
    visited[i][j] = true;
    vector <vector<char> > board = b->getLetters();
    str = str + board[i][j];

    if (board[i][j] == 'q') {
        str = str + 'u';
    }
    if (!trie->startsWith(str)) {

        if (str[str.length()-2] == 'q' && str.back() == 'u') {
            str.erase(str.length()-2);
        } else {
            str.erase(str.length() - 1);
        }
        visited[i][j] = false;
        return;
    }

    if (str.length() > 5 && trie->search(str) && (find(words.begin(), words.end(), str) == words.end())) {
        words.push_back(str);
    }

    for (int row = i - 1; row <= i + 1 && row < b->getSize(); row++) {
        for (int col = j - 1; col <= j + 1 && col < b->getSize(); col++) {
            if (row >= 0 && col >= 0 && !visited[row][col]) {
                DFS(b, visited, row, col, str);
            }
        }
    }

    if (str[str.length()-2] == 'q' && str.back() == 'u') {
        str.erase(str.length()-2);
    } else {
        str.erase(str.length() - 1);
    }
    visited[i][j] = false;
}

int main(int argc, char* argv[0]) {
    ifstream file(argv[1]);
    istream_iterator<string> eos;
    istream_iterator<string> iit = istream_iterator<string>(file);
    cerr << "Expected format: main " << endl;
    cerr << "<words>  list of dictionary words" << endl;
    cerr << "<board>  a 2D board of NxN letters." << endl;
    if (!argv[1]) {
        cerr << "Please provide a words.txt file as the first parameter." << endl;
        return 1;
    }

    if (!argv[2]) {
        cerr << "Please provide a boards.txt file as the first parameter." << endl;
        return 1;
    }

    string word;
    while(iit != eos) {
        trie->insert(*iit);
        ++iit;
    }

    int input;
    cout << "Please select the size of board you want. (4 for a 4x4 board, 5 for a 5x5 board, etc.)" << endl;
    cin >> input;

    ifstream boardFile(argv[2]);
    istream_iterator<string> bEos;
    istream_iterator<string> bIit = istream_iterator<string>(boardFile);
    vector <vector<char> > board;

    while(bIit != bEos) {
        vector<char> row;
        for (auto &i : *bIit) {
            row.push_back(std::tolower(i));
        }
        board.push_back(row);
        ++bIit;
    }
    Board *b;
    try {
        b = new Board(input, board);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
        return 1;
    }
    vector<vector<bool> > visited(b->getSize(), vector<bool>(b->getSize(), false));
    string str = "";

    for (int i = 0; i < b->getSize(); i++) {
        for (int j = 0; j < b->getSize(); j++) {
            DFS(b, visited, i, j, str);
        }
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++) {
        cerr << words[i] << endl;
    }
    return 0;
}