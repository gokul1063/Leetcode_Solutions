class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:

        res = []

        def helper(nums, ind, local) :
            if ind == len(nums):
                res.append(local)
                return 
            helper(nums, ind + 1, local + [nums[ind]])
            helper(nums, ind + 1, local )
        helper(nums, 0, [])
        return res

            
        