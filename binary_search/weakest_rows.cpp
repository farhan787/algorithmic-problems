// Problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int countSoldiers(vector<int>& arr) {
    int soldier = 0;

    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == 1) {
            soldier = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return soldier;
}

// Time => O(rows * log(cols))
// Space => O(rows)
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> weakestRows;
    vector<pair<int, int>> soldiers;

    for (int i = 0; i < (int)mat.size(); i++) {
        int soldier = countSoldiers(mat[i]);
        soldiers.push_back(make_pair(soldier, i));
    }

    sort(soldiers.begin(), soldiers.end());

    for (int i = 0; i < k; i++) weakestRows.push_back(soldiers[i].second);
    return weakestRows;
}

int main() {
}
