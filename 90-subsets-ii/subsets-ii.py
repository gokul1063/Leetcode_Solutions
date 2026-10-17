# method 2

class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        res = []
        res.append([])
        n = len(nums)

        for i in range(0,n):
            res2 = []
            for ele in res :
                checker = sorted(ele + [nums[i]])
                if checker not in res:
                    res2.append(checker)
            print(res2)
            res.extend(res2)
            #print(res2)
            
        return res



