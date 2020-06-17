#include <iostream>
using namespace std;

int sqrt(int x) {
    if (x < 2) return x;

    int left = 0;
    int right = x;

    int sqrtFound = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid == x / mid) {
            return mid;
        } else if (mid > x / mid) {
            sqrtFound = mid;
            right = mid - 1;
        } else if (mid < x / mid) {
            left = mid + 1;
        }
    }
    return sqrtFound - 1;
}

int main() {
    int x;
    cin >> x;
    cout << sqrt(x) << endl;
}
