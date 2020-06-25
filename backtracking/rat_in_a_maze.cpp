#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Direction {
    int row;
    int col;
    string name;

    Direction(int row, int col, string name) {
        this->row = row;
        this->col = col;
        this->name = name;
    }
};

vector<Direction> directions = {
    Direction(-1, 0, "U"),
    Direction(1, 0, "D"),
    Direction(0, 1, "R"),
    Direction(0, -1, "L"),
};

bool outOfMaze(int row, int col, int maze_size) {
    if (row < 0 || col < 0 || row >= maze_size || col >= maze_size) return true;
    return false;
}

void mazePaths(vector<string>& paths, string& path, int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& m) {
    const int maze_size = (int)m.size();
    if (row == maze_size - 1 && col == maze_size - 1 && m[row][col] == 1) {
        paths.push_back(path);
        return;
    }

    // if blocked or visited cell then return
    if (m[row][col] == 0 || visited[row][col]) {
        return;
    }

    visited[row][col] = true;

    for (Direction dir : directions) {
        int newRow = row + dir.row;
        int newCol = col + dir.col;
        if (outOfMaze(newRow, newCol, maze_size)) continue;

        path += dir.name;
        mazePaths(paths, path, newRow, newCol, visited, m);
        path.pop_back();
    }
    visited[row][col] = false;
}

vector<string> printPath(vector<vector<int>>& m) {
    vector<string> paths;

    string path = "";
    vector<vector<bool>> visited(m.size(), vector<bool>(m.size(), false));

    mazePaths(paths, path, 0, 0, visited, m);
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    vector<vector<int>> m = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}};

    // int m[MAX][MAX] = {
    //     {1, 0},
    //     {1, 0}};

    // int m[MAX][MAX] = {
    //     {1, 0, 0, 0},
    //     {1, 1, 0, 1},
    //     {0, 1, 0, 0},
    //     {0, 1, 1, 1},
    // };

    vector<string> paths = printPath(m);
    // print paths
}
