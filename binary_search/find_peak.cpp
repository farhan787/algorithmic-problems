#include <iostream>
#include <vector>
using namespace std;

// Find peak element in an array
// peak element is defined as a[i],
// a[i - 1] < a[i] > a[i + 1]

// Time => O(n)
// Space => O(1)
int findPeakElement(int* nums, int n) {
    if (n == 1) return 0;

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid - 1] > nums[mid]) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return left;
}

int main() {
    // int nums[] = {1, 2};
    int nums[] = {1, 2, 1, 3, 5, 6, 4};
    // int nums[] = {2, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    int peakIndex = findPeakElement(nums, size);
    cout << peakIndex << endl;
}
