https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex; // Stores number -> index mapping
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // What number do we need to reach target?
        if (numIndex.find(complement) != numIndex.end()) {  //
            return {numIndex[complement], i}; // Found the pair
        }
        numIndex[nums[i]] = i; // Store current number's index
    }
    return {};
    }
};

// https://chatgpt.com/share/67aa700d-a744-8002-912f-e47c6d24034d