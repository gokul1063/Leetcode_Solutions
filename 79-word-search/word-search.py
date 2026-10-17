class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        
        # 👇 Using characters directly as keys preserves case sensitivity ('a' != 'A')
        data = {}

        for i, ele in enumerate(board):
            for j, ch in enumerate(ele): 
                if ch not in data:
                    data[ch] = []
                data[ch].append((i, j))
        
        res = False

        def back(prev, ind, m, visited):
            nonlocal res
            if res:
                return
                
            if ind == m:
                res = True
                return 
            
            prev_i = prev[0]
            prev_j = prev[1]

            # 👇 Fetch coordinates matching the exact case of the current target character
            points = data.get(word[ind], [])
            possible_points = []

            for ele in points: 
                ele_i = ele[0]
                ele_j = ele[1]

                if ele not in visited:
                    if (ele_i == prev_i) and (ele_j == prev_j + 1 or ele_j == prev_j - 1):
                        possible_points.append(ele)
                    if (ele_i == prev_i - 1 or ele_i == prev_i + 1) and (ele_j == prev_j): 
                        possible_points.append(ele)
                
            for ele in possible_points:
                if res:
                    break
                back(ele, ind + 1, m, visited | {ele})
        
        for ele in data.get(word[0], []):
            if res:
                break
            back(ele, 1, len(word), {ele})
        
        return res