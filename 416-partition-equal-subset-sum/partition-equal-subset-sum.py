class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        nums.sort()

        total = sum(nums)
        if total % 2 == 1 :
            return False
        n = total // 2

        dp = [False] * (n + 1)

        dp[0] = True

        for ele in nums[::-1] :
            local_cal = []
            for i in range(n + 1):
                #print(f"inside loop with {i = }, {ele = }, {dp = }")
                if dp[i] and i + ele <= n:
                    local_cal.append(i)
            
            #dp updating ...

            for j in local_cal :
                dp[ele + j] = True

            #print(f"{dp = }")
            if dp[n] :
                return True
        return False
                    
                    