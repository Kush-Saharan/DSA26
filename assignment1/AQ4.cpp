/*
You are given a 1D array that may contain both positive and negative integers, and find
the sum of a contiguous subarray of numbers which has the largest sum. For example, if
the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxCrossingSum(vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN, sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArraySum(vector<int>& arr, int low, int high) {
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    int leftMax  = maxSubArraySum(arr, low, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);

    return max({leftMax, rightMax, crossMax});
}

int main() {
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << maxSubArraySum(arr, 0, arr.size() - 1);

    return 0;
}
