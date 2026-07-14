class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        numSet = set(nums) # Convert into a hash set for an O(1) lookup
        longest = 0

        for num in numSet:
            if (num - 1) not in numSet: # Start a new sequence
                length = 1
                while (num + length) in numSet:
                    length += 1
                longest = max(length, longest)
        return longest