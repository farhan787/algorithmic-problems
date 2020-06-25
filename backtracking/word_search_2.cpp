// Problem: https://leetcode.com/problems/word-search-ii

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TrieNode {
   public:
    char data;
    bool isWordEnding;
    unordered_map<char, TrieNode*> neighbours;

    TrieNode(char ch, bool isWordEnding = false) {
        this->data = ch;
        this->isWordEnding = isWordEnding;
    }
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode('*');
    }

    void addWord(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            TrieNode* node = new TrieNode(ch);

            bool isCharPresent = temp->neighbours.count(ch);
            if (isCharPresent) {
                // move towards it
                temp = temp->neighbours[ch];
            } else {
                // insert it as neighbour of current node
                temp->neighbours.insert({ch, node});
                temp = node;
            }
        }
        temp->isWordEnding = true;
    }
};

bool isValidCell(vector<vector<char>>& board, int row, int col) {
    const int board_rows = (int)board.size();
    const int board_cols = (int)board[0].size();

    return row >= 0 && col >= 0 && row < board_rows && col < board_cols;
}

Trie buildTrie(vector<string>& words) {
    Trie trie;
    for (string& word : words) {
        trie.addWord(word);
    }
    return trie;
}

void searchWord(vector<vector<char>>& board, int row, int col, string& word, TrieNode* trieRoot, unordered_set<string>& foundWords) {
    if (!isValidCell(board, row, col) || board[row][col] == ' ') return;

    const char currChar = board[row][col];

    bool currCharTrieRootNbr = trieRoot->neighbours.count(currChar);
    // Branch Pruning
    if (!currCharTrieRootNbr) return;

    word.push_back(currChar);
    board[row][col] = ' ';

    trieRoot = trieRoot->neighbours[currChar];
    if (trieRoot->isWordEnding) {
        foundWords.insert(word);
    }

    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (auto dir : directions) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        searchWord(board, newRow, newCol, word, trieRoot, foundWords);
    }

    board[row][col] = currChar;
    word.pop_back();
}

// Time complexity => O(W * C + rows^2 * cols^2); where W = words.size() and C = max char len of a word in words
// Space complexity => O(total_chars_in_words_vector)

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> foundWords;

    unordered_set<string> result;
    Trie trie = buildTrie(words);

    for (int row = 0; row < (int)board.size(); row++) {
        for (int col = 0; col < (int)board[0].size(); col++) {
            string word = "";
            TrieNode* trieRoot = trie.root;

            searchWord(board, row, col, word, trieRoot, result);
        }
    }

    for (auto word : result) foundWords.push_back(word);

    return foundWords;
}

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> foundWords = findWords(board, words);
    printVec(foundWords);
}
