class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        sols = []
        nums.sort()

        for i in range(len(nums)):
            if nums[i] > 0:
                break  # if the smallest remaining number is non-zero then nothing will add up to zero

            if i  > 0 and nums[i] == nums[i-1]:
                continue # If the next number is the same as the one we just went over we'll just find the same solution
            
            j = i + 1 # pointer 1 right in front of i 
            k = len(nums) - 1 # pointer 2 on the right edge

            while j < k:
                current_sum = nums[i] + nums[j] + nums[k]
                if current_sum == 0:
                    sols.append([nums[i] , nums[j] , nums[k]])
                    j += 1
                    k -= 1

                    while j < k and nums[j] == nums[j-1]: 
                        j += 1
                    while j < k and nums[k] == nums[k+1]: 
                        k -= 1
                else:
                    if current_sum < 0: 
                        j += 1 # since nums is sorted moving the left pointer to a bigger index so that the sum becomes larger
                    elif current_sum > 0: 
                        k -=1   # move right pointer to a smaller index so that the sum becomes smaller
        return sols
        