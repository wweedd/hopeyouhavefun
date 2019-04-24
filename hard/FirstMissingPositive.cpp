/*
 * Given an unsorted integer array, find the smallest missing positive
 * integer. Your algorithm should run in O(n) time with constant extra
 * space.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */
#include <utility>
#include <vector>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i]!=nums[nums[i]-1]) {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.back()+1;
    }
};
