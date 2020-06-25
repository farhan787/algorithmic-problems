// Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number

#include <iostream>
#include <vector>

using namespace std;

vector<string> dialpad = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void phoneLetterCombinations(string digits, int digitIndex, string combination, vector<string>& combinations) {
    if (digitIndex == (int)digits.size()) {
        combinations.push_back(combination);
        return;
    }

    int digit = digits[digitIndex] - '0';
    for (char letter : dialpad[digit]) {
        combination += (char)tolower(letter);
        phoneLetterCombinations(digits, digitIndex + 1, combination, combinations);
        combination.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) return combinations;

    string combination = "";
    int digitIndex = 0;
    phoneLetterCombinations(digits, digitIndex, combination, combinations);

    return combinations;
}

int main() {
}
