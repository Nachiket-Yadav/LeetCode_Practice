// Heap solution

#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> freqs;

        for (int i = 0; i < nums.size();i++){
            freqs[nums[i]]++; // Get the counts for each number
        }

        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> heap;

        for (auto& entry : freqs){
            heap.push({entry.second,entry.first});
            if (heap.size() > k){
                heap.pop();
            }
        }

        std::vector<int> res;

        for (int i = 0; i < k; i++){
            res.push_back(heap.top().second); // Save the top entry
            heap.pop(); // Remove the top 
        }
        
        return res;
    }


};

// Bucket sort solution

class Solution2 {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> freqs;
        std::vector<std::vector<int>> buckets(nums.size() + 1);

        for (int i = 0; i < nums.size();i++){
            freqs[nums[i]]++; // Get the counts for each number
        }

        for (const auto& entry : freqs){
            buckets[entry.second].push_back(entry.first);
        }

        std::vector<int> res;
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};