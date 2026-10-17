class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []

        def back(l,r,curr):
            if l == 0 and r == 0 :
                res.append(curr)
                return
            
            if (l > 0):
                back(l-1,r,curr + '(')
            if (l < r):
                back(l, r-1, curr + ')')


        back(n,n,"")
        return res