class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        res = []
        current = []

        def helper(start, remaining):
            if remaining == 0:
                res.append(current.copy())
                return 
            if remaining < 0 :
                return 
            
            for i in range(start, len(candidates)):
                current.append(candidates[i])
                helper(i, remaining - candidates[i] )
                current.pop()
        
        helper(0,target)

        return res