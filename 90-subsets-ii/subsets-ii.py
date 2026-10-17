class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        res = []
        n = len(nums)

        for i in range(0,(2**n )+1): 
            bval = bin(i)[2:].zfill(n)


            curr = []
            for ele in range(n):
                if bval[ele] == '1':
                    curr.append(nums[ele])
            
            curr.sort()
            if (curr not in res):
                res.append(curr)
            
        return res


