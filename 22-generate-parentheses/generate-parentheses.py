class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []

        def back(curr, balance, formed) :
            if balance < 0 : 
                return
                
            if formed == n and len(curr) == 2 * n: 
                if curr not in res :
                    res.append(curr)
                return 
            if len(curr) > 2 * n :
                return 
            
             
            back(curr + '(', balance + 1, formed)
            back(curr + ')', balance - 1, formed + 1)

        back('', 0, 0)
        return res