class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        prefix = [0] * n
        suffix = [0] * n


        prefix[0] = suffix[n-1] = 1

        for i in range(1,n): # Forward pass
            prefix[i] = prefix[i-1] * nums[i-1]

        for i in range(n - 2, -1, -1): # Backward pass
            suffix[i] = suffix[i+1] * nums[i+1]

        res = [prefix[i] * suffix[i] for i in range(n)]
        return res