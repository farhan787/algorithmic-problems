// Problem: https://leetcode.com/problems/letter-case-permutation/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Time complexity => O(2^|S|)
// Space complexity => O(|S|)

// DFS Solution with backtracking
void generatePermutations(string& S, vector<string>& permutations, int currIndex, string& str) {
    if (currIndex == (int)S.length()) {
        permutations.push_back(str);
        return;
    }

    if (S[currIndex] >= '0' && S[currIndex] <= '9') {
        str += S[currIndex];
        generatePermutations(S, permutations, currIndex + 1, str);
        str.pop_back();
    } else {
        // use the lower case letter
        str += tolower(S[currIndex]);
        generatePermutations(S, permutations, currIndex + 1, str);
        str.pop_back();

        // use the upper case letter
        str += toupper(S[currIndex]);
        generatePermutations(S, permutations, currIndex + 1, str);
        str.pop_back();
    }
}

vector<string> letterCasePermutation(string S) {
    vector<string> permutations;

    string str = "";
    generatePermutations(S, permutations, 0, str);

    return permutations;
}

// BFS Solution
bool isNum(char ch) {
    return ch >= '0' && ch <= '9';
}

vector<string> letterCasePermutationBFS(string S) {
    vector<string> permutations;

    queue<string> q;
    q.push("");
    q.push("level_end");

    for (int i = 0; i < (int)S.length(); i++) {
        char ch = S[i];

        while (q.front() != "level_end") {
            string front = q.front();
            if (isNum(ch)) {
                q.push(front + ch);
            } else {
                q.push(front + (char)tolower(ch));
                q.push(front + (char)toupper(ch));
            }
            q.pop();
        }
        q.push("level_end");
        q.pop();
    }

    while (!q.empty()) {
        permutations.push_back(q.front());
        q.pop();
    }
    // to remove "level_end" string from permutations vector
    permutations.pop_back();

    return permutations;
}

int main() {
    string input = "a1b2";
    vector<string> permutations = letterCasePermutation(input);
}
