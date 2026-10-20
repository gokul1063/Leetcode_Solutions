class Solution:
    def partition(self, s: str) -> list[list[str]]:
        res = []
        n = len(s)
        def back(ind, currL):
            if ind == n : 
                res.append(currL[::])
                return 
            
            for i in range(ind, n) :
                rear = s[ind:i+1] 
         

                if rear == rear[::-1] :
                    back(i + 1, currL + [rear] )

        back(0,[])
        return res
