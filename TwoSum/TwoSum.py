class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}

        for i,num in enumerate(nums):
            diff = target - num

            if diff in table.keys(): # found the two sum
                return [i,table[diff]]

            if num not in table.keys(): # store the number in the map
                table[num] = i
        return None
