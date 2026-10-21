class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        data = {
            "1": "",
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
            "*": "",
            "0": "",
            "#": ""
        }
        
        res = []
        n = len(digits)

        def back(ind, curr) :
            if ind == n : 
                res.append(curr)
                return 
            
            elements = data[digits[ind]]

            for char in elements : 
                back(ind+1, curr + char)
            
        back(0, "")

        return res
