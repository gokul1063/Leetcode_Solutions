class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        res = []

        board = [['.'] * n for _ in range(n)]
        
        def possible(row, col, board): 
            # same col : 

            for i in range(row) : 
                if board[i][col] == 'Q' :
                    return False
            
            # postive diagnoal 
            r,c = row, col 

            while r >= 0 and c < n : 
                if board[r][c] == 'Q' : 
                    return False
                r -= 1
                c += 1
            
            # negative diagnoal 

            r,c = row, col 

            while r >= 0 and c >= 0 : 
                if board[r][c] == 'Q' : 
                    return False
                r -= 1
                c -= 1
            
            return True
        

        def back(row, board) : 
            if row == n : 
                mat = []

                for ele in board : 
                    mat.append(''.join(ele))
                res.append(mat)
                return 
            
            for i in range(n) :

                if possible (row, i , board) :
                    board[row][i] = 'Q'
                    back(row + 1 , board)
                    board[row][i] = '.'

        back(0,board)

        return res