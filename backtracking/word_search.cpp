// Problem: https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>

using namespace std;

bool isValidCell(vector<vector<char>>& board, int row, int col) {
    const int board_rows = (int)board.size();
    const int board_cols = (int)board[0].size();

    return row >= 0 && col >= 0 && row < board_rows && col < board_cols;
}

bool searchWord(vector<vector<char>>& board, int row, int col, string& word, int wordPointer, vector<vector<bool>>& visited) {
    if (wordPointer == (int)word.length()) return true;

    if (!isValidCell(board, row, col) || visited[row][col]) return false;
    if (board[row][col] != word[wordPointer]) return false;

    visited[row][col] = true;

    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (auto dir : directions) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        bool wordFound = searchWord(board, newRow, newCol, word, wordPointer + 1, visited);
        if (wordFound) return true;
    }
    visited[row][col] = false;

    return false;
}

// Time complexity => O(rows * cols * 4^|word|)
// Space complexity => O((rows * cols) + |word|)
bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    for (int row = 0; row < (int)board.size(); row++) {
        for (int col = 0; col < (int)board[0].size(); col++) {
            if (board[row][col] == word[0]) {
                int wordPointer = 0;
                bool isWordFound = searchWord(board, row, col, word, wordPointer, visited);
                if (isWordFound) return true;
            }
        }
    }
    return false;
}

int main() {
}
