// Problem: https://leetcode.com/problems/koko-eating-bananas/

#include <iostream>
#include <vector>

using namespace std;

int getMaxBananas(vector<int>& piles) {
    int maxBanans = INT_MIN;
    for (int banana : piles) {
        maxBanans = max(maxBanans, banana);
    }
    return maxBanans;
}

bool canEatAllBananas(vector<int>& piles, int eatingSpeed, int H) {
    long long int time = 0;
    for (int i = 0; i < (int)piles.size(); i++) {
        int banana = piles[i];
        time += banana / eatingSpeed;
        time += (banana % eatingSpeed == 0) ? 0 : 1;
    }
    return (int)time <= H;
}

// Time Complexity => O(|piles| * log(maxBanana)) where maxBanana is largest pile in piles
// Space Complexity => O(1)
int minEatingSpeed(vector<int>& piles, int H) {
    int minEatSpeed = INT_MAX;
    int maxBananas = getMaxBananas(piles);

    int left = 1;
    int right = maxBananas;

    while (left <= right) {
        int eatingSpeed = left + (right - left) / 2;
        if (canEatAllBananas(piles, eatingSpeed, H)) {
            minEatSpeed = min(minEatSpeed, eatingSpeed);
            right = eatingSpeed - 1;
        } else {
            left = eatingSpeed + 1;
        }
    }

    return minEatSpeed;
}

int main() {
    vector<int> piles = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    int H = 823855818;

    cout << minEatingSpeed(piles, H) << endl;
}
