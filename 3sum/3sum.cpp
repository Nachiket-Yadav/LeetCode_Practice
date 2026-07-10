#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;
        std::sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i ++){
            
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k ){

                int total = nums[i] + nums[j] + nums[k];

                if (total == 0){
                    sol.push_back({nums[i] , nums[j] , nums[k]});

                    j++;

                    while(nums[j] == nums[j-1] && j < k){
                        j++;
                    }
                }
                else if (total < 0){
                    j++;
                }
                else if (total > 0){
                    k--;
                }

            }

        }
        return sol;
    }
    
};