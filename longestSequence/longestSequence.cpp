#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> hashSet;

        for (int num : nums){
            hashSet.insert(num);
        }

        int maxLen = 0;

        for (int num : hashSet){
            int curLen = 0;
            if (hashSet.find(num-1) == hashSet.end()){
                curLen++;

                while (hashSet.find(num+curLen) != hashSet.end()){
                    curLen++;
                }

                if (curLen > maxLen){
                    maxLen = curLen;
                }
                
            }
        }

        return maxLen;

    }
};