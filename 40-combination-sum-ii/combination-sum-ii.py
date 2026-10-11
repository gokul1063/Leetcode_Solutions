class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()

        res = []
        current = []

        def helper(start, remaining):
            if remaining == 0:
                res.append(current.copy())
                return
            if remaining < 0 :
                return 
            
            for i in range(start, len(candidates)):

                if i > start and candidates[i] == candidates[i-1] :
                    continue
                current.append(candidates[i])
                
                helper(i+1, remaining - candidates[i])

                current.pop()
            
        helper(0, target)

        return res