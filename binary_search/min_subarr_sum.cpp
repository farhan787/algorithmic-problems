// Problem link: https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>

using namespace std;

vector<int> getCumulativeSum(vector<int>& nums) {
    vector<int> sums(nums.size(), 0);
    if (nums.empty()) return sums;

    sums[0] = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        sums[i] = sums[i - 1] + nums[i];
    }
    return sums;
}

int getSubArrSum(vector<int>& cumSum, int startIndex, int endIndex) {
    return cumSum[endIndex] - (startIndex > 0 ? cumSum[startIndex - 1] : 0);
}

int getMinArrLen(vector<int>& nums, int startIndex, vector<int>& numsSums, int s) {
    int minArrLen = INT_MAX;

    int left = startIndex;
    int right = (int)nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = getSubArrSum(numsSums, startIndex, mid);
        if (sum < s) {
            left = mid + 1;
        } else {
            int currLen = mid - startIndex + 1;
            minArrLen = min(minArrLen, currLen);
            right = mid - 1;
        }
    }
    return minArrLen;
}

// Time complexity => O(n * log n)
// Space complexity => O(1)
int minSubArrayLen(int s, vector<int>& nums) {
    int minSubArrLen = INT_MAX;

    vector<int> numsSums = getCumulativeSum(nums);

    for (int i = 0; i < (int)nums.size(); i++) {
        int currLen = getMinArrLen(nums, i, numsSums, s);
        minSubArrLen = min(minSubArrLen, currLen);
    }
    return minSubArrLen == INT_MAX ? 0 : minSubArrLen;
}

// Time complexity => O(nums.size())
// Space complexity => O(1)
int minSubArrayLen_(int s, vector<int>& nums) {
    int minSubArrLen = INT_MAX;
    int windowStart = 0;
    int sum = 0;
    for (int windowEnd = 0; windowEnd < (int)nums.size(); windowEnd++) {
        sum += nums[windowEnd];
        while (sum >= s) {
            int windowLen = windowEnd - windowStart + 1;
            minSubArrLen = min(minSubArrLen, windowLen);
            sum -= nums[windowStart++];
        }
    }
    return minSubArrLen == INT_MAX ? 0 : minSubArrLen;
}

int main() {
}
