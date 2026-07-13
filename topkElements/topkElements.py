# Sorting Solution

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freqs = {}
        for num in nums:
            freqs[num] = freqs.get(num, 0) + 1 # increment entry
        
        sorted_by_value = dict(sorted(freqs.items(), key= lambda item: item[1],reverse=True))
        return list(sorted_by_value)[:k]
    
# Min Heap Solution
import heapq
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freqs = {}
        for num in nums:
            freqs[num] = freqs.get(num, 0) + 1 # increment entry
        
        heap = [] 
        for num,count in freqs.items():
            heapq.heappush(heap,(count,num)) # keeps the minimimum frequency on top of the heap

            if len(heap) > k:
                heapq.heappop(heap)
        
        res = []
        for i in range(k):
            res.append(heapq.heappop(heap)[1])
        return res

# Bucket sort solution

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freqs = {} # Dict of frequency counts
        buckets = [[] for i in range(len(nums))] # buckets for each frequence; Each index corresponds to the the frequency and will be appended with the 
                                                # num of matching frequency.
        for num in nums:
            freqs[num] = freqs.get(num, 0) + 1 # increment entry

        for num,count in freqs.items():
            buckets[count-1].append(num)
        
        res = []
        for lst in buckets[::-1]:
            for num in lst:
                res.append(num)
                if len(res) == k:
                    return res
        
        