#include <iostream>
#include <vector>

using namespace std;

void printPermutations(string& inp, int i) {
    if (i == (int)inp.size()) {
        cout << inp << ", ";
        return;
    }

    for (int j = i; j < (int)inp.size(); j++) {
        swap(inp[i], inp[j]);
        printPermutations(inp, i + 1);

        swap(inp[i], inp[j]);
    }
}

void printSortedPermutations(string out, int outPointer, vector<int>& counts) {
    if (outPointer == (int)counts.size() - 1) {
        cout << out << ", ";
        return;
    }

    for (int x = 1; x < (int)counts.size(); x++) {
        if (counts[x] > 0) {
            out.push_back((char)(x + '0'));
            counts[x]--;
            printSortedPermutations(out, outPointer + 1, counts);

            out.pop_back();
            counts[x]++;
        }
    }
}

int main() {
    string input = "123";

    vector<int> counts(input.length() + 1, 1);
    counts[0] = 0;

    string out = "";
    int outPointer = 0;

    printSortedPermutations(out, outPointer, counts);

    cout << endl;
}
