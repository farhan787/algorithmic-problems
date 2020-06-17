#include <iostream>
#include <vector>
using namespace std;

int getTotalPages(vector<int>& bookPages) {
    int totalPages = 0;
    for (int page : bookPages) {
        totalPages += page;
    }
    return totalPages;
}

bool isValidConfig(vector<int>& bookPages, int maxPagesLimit, int totalStudent) {
    int student = 1;
    int pagesRead = 0;

    for (int i = 0; i < (int)bookPages.size(); i++) {
        if (bookPages[i] > maxPagesLimit) {
            return false;
        }

        if (pagesRead + bookPages[i] > maxPagesLimit) {
            student++;
            pagesRead = bookPages[i];

            if (student > totalStudent) {
                return false;
            }
        } else {
            pagesRead += bookPages[i];
        }
    }
    return true;
}

int minMaxBookPages(vector<int>& bookPages, int n, int totalStudent) {
    if (totalStudent > n) {
        return -1;
    }

    int minPages = bookPages[0];
    int maxPages = getTotalPages(bookPages);

    int finalMinMaxPages = -1;
    while (minPages <= maxPages) {
        int maxPagesLimit = minPages + (maxPages - minPages) / 2;

        if (isValidConfig(bookPages, maxPagesLimit, totalStudent)) {
            finalMinMaxPages = maxPagesLimit;
            maxPages = maxPagesLimit - 1;
        } else {
            minPages = maxPagesLimit + 1;
        }
    }
    return finalMinMaxPages;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, m;
        cin >> n;

        vector<int> bookPages;
        for (int i = 0; i < n; i++) {
            int pages;
            cin >> pages;
            bookPages.push_back(pages);
        }
        cin >> m;
        cout << minMaxBookPages(bookPages, n, m) << endl;
    }
}
