// Problem: https://leetcode.com/problems/number-of-matching-subsequences/

#include <iostream>
#include <vector>
using namespace std;

int findMatchingCharIndex(char ch, vector<vector<int>>& SCharIndices, int lastMatchCharIndex) {
    int matchingCharIndex = -1;

    int left = 0;
    int right = SCharIndices[ch - 'a'].size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int currIndex = SCharIndices[ch - 'a'][mid];

        if (currIndex > lastMatchCharIndex) {
            matchingCharIndex = currIndex;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return matchingCharIndex;
}

bool isSubsequence(string& word, vector<vector<int>>& SCharIndices) {
    // S = "abcde"
    // word = "ace"

    //      represents  a   b   c   d   e..........z
    // SCharIndices = [[0],[1],[2],[3],[4],......[-1]] -1 for z means, no z character

    int lastMatchCharIndex = -1;

    for (char ch : word) {
        int charMatchIndex = findMatchingCharIndex(ch, SCharIndices, lastMatchCharIndex);
        if (charMatchIndex == -1) return false;
        lastMatchCharIndex = charMatchIndex;
    }
    return true;
}

vector<vector<int>> getCharIndices(string& str) {
    vector<vector<int>> charIndices(26);
    for (int i = 0; i < (int)str.length(); i++) {
        char ch = str[i];
        charIndices[ch - 'a'].push_back(i);
    }
    return charIndices;
}

// Time Complexity => O(|S| + |words| * |maxWordInWords| * log(|S|))
// Space Complexity => O(|S|)
int numMatchingSubseq(string S, vector<string>& words) {
    int matchingSubseqCount = 0;

    vector<vector<int>> SCharIndices = getCharIndices(S);

    for (string word : words) {
        if (isSubsequence(word, SCharIndices)) {
            ++matchingSubseqCount;
        }
    }
    return matchingSubseqCount;
}

int main() {
    string S = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};

    cout << numMatchingSubseq(S, words) << endl;
}
