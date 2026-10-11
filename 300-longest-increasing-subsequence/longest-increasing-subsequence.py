class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        n = len(nums)
        dp = [1]*n

        for i in range(n):
            local_len = 0
            for j in range(i):
                if (nums[i] > nums[j]) :
                    local_len = max(local_len , dp[j])
            dp[i] = local_len + 1
        return max(dp)