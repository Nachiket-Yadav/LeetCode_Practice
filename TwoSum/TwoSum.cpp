#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int,int> seen; // Create hashmap

        for (int i = 0; i < nums.size();i++){
            int diff = target - nums[i]; 

            if (seen.find(diff) != seen.end()){ // Check if the difference is in the hashmap / we've already seen this 
                return {i,seen[diff]};
            }

            seen[nums[i]] = i; // Add current number to the hashmap / we've seen the current number
        }
        return {};
    }
};