// Problem: https://leetcode.com/problems/sudoku-solver

#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

// Time complexity => O(9^(rows * cols) * (rows * cols))  second one for checking the subgrid if it contains any repeated number
// Space complexity => O(rows * cols)

bool isSafe(char num, vector<vector<char>>& board, int row, int col) {
    // check if num exist in row
    for (int j = 0; j < (int)board.size(); j++) {
        if (board[row][j] == num) return false;
    }

    // check if num exist in col
    for (int i = 0; i < (int)board.size(); i++) {
        if (board[i][col] == num) return false;
    }

    // check if num exist in subgrid
    int subgrid_size = sqrt((int)board.size());
    int subgrid_row_start = (row / subgrid_size) * subgrid_size;
    int subgrid_col_start = (col / subgrid_size) * subgrid_size;

    for (int r = subgrid_row_start; r < subgrid_row_start + subgrid_size; r++) {
        for (int c = subgrid_col_start; c < subgrid_col_start + subgrid_size; c++) {
            if (board[r][c] == num) return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<char>>& board, int row, int col) {
    const int board_size = (int)board.size();

    if (row == board_size) {
        return true;
    }

    if (col == board_size) {
        return sudokuSolver(board, row + 1, 0);
    }

    if (board[row][col] != '.') {
        return sudokuSolver(board, row, col + 1);
    }

    for (char num = '1'; num <= '9'; num++) {
        if (isSafe(num, board, row, col)) {
            board[row][col] = num;
            bool sudokuCanBeSolvedFurther = sudokuSolver(board, row, col + 1);
            if (sudokuCanBeSolvedFurther) return true;
        }
    }
    board[row][col] = '.';
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    bool isSolved = sudokuSolver(board, 0, 0);
}

int main() {
}
