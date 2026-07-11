#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution { // Hash Set
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        for(int num : nums){
            if (seen.find(num) != seen.end()){
                return true;
            }
            else {
                seen.insert(num);
            }
        }
        return false;
    }
};


class Solution { // Space optimized
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Sort the array in ascending order
        std::sort(nums.begin(), nums.end());
        
        // Check if any adjacent elements are identical
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        
        return false;
    }
};