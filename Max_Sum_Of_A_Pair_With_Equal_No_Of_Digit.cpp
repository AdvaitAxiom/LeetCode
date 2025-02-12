#include<bits/stdc++.h>
using namespace std;

class Solution {
    int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitSumMap;
    int maxResult = -1;

    // Group numbers by their digit sum
    for (int num : nums) {
        int sum = sumOfDigits(num);
        digitSumMap[sum].push_back(num);
    }

    // Find the maximum pair sum for each group
    for (auto& entry : digitSumMap) {
        vector<int>& values = entry.second;
        if (values.size() > 1) {
            // Get the two largest numbers in the group
            sort(values.rbegin(), values.rend());  // Sort in descending order
            maxResult = max(maxResult, values[0] + values[1]);
        }
    }

    return maxResult;
    }
};

int main(){

    return 0;
}