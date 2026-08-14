class Solution {
private:

    vector<vector<int>> prefix;


    int getSum(int r1, int c1, int r2, int c2) {

        if (r1 > r2 || c1 > c2)
            return 0;

        return prefix[r2 + 1][c2 + 1]
             - prefix[r1][c2 + 1]
             - prefix[r2 + 1][c1]
             + prefix[r1][c1];
    }


    bool check_square(pair<int,int> top_left,
                      int square_len,
                      int m,
                      int n) {

        int r = top_left.first;
        int c = top_left.second;

        int bottom = r + square_len - 1;
        int right  = c + square_len - 1;

        if (bottom >= m || right >= n)
            return false;


        // Check new right column
        int right_col_sum =
            getSum(r, right, bottom, right);

        if (right_col_sum != square_len)
            return false;


        // Check new bottom row
        int bottom_row_sum =
            getSum(bottom, c, bottom, right);

        if (bottom_row_sum != square_len)
            return false;


        return true;
    }


    bool separate_square(pair<int,int> A,
                         pair<int,int> B,
                         int len) {

        int A_right  = A.second + len - 1;
        int A_bottom = A.first + len - 1;

        int B_right  = B.second + len - 1;
        int B_bottom = B.first + len - 1;


        // A completely left of B
        if (A_right < B.second)
            return true;

        // B completely left of A
        if (B_right < A.second)
            return true;

        // A completely above B
        if (A_bottom < B.first)
            return true;

        // B completely above A
        if (B_bottom < A.first)
            return true;


        return false;
    }


    bool check_2_unique(vector<pair<int,int>>& points, int len) {
    
        int n = points.size();
    
        if (n < 2)
            return false;
    
        int min_row = INT_MAX;
        int min_col = INT_MAX;
    
        int max_row = INT_MIN;
        int max_col = INT_MIN;
    
        for (auto p : points) {
            min_row = min(min_row, p.first);
            min_col = min(min_col, p.second);
    
            max_row = max(max_row, p.first);
            max_col = max(max_col, p.second);
        }
    
        // Two squares can be separated horizontally
        if (max_col - min_col >= len)
            return true;
    
        // Two squares can be separated vertically
        if (max_row - min_row >= len)
            return true;
    
        return false;
    }

public:

    int maxArea(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        prefix.assign(m + 1, vector<int>(n + 1, 0));


        // Build prefix sum
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                prefix[i + 1][j + 1] =
                    mat[i][j]
                    + prefix[i][j + 1]
                    + prefix[i + 1][j]
                    - prefix[i][j];
            }
        }


        // Candidate top-left points
        vector<pair<int,int>> candidates;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 1)
                    candidates.push_back({i, j});
            }
        }


        int answer = 0;


        // Two separate 1x1 squares
        if (candidates.size() >= 2)
            answer = 1;


        int max_len = min(m, n);


        for (int len = 2; len <= max_len; len++) {

            vector<pair<int,int>> next_candidates;


            for (auto point : candidates) {

                if (check_square(point, len, m, n)) {

                    next_candidates.push_back(point);
                }
            }


            if (next_candidates.empty())
                break;


            if (!check_2_unique(next_candidates, len))
                break;


            candidates = move(next_candidates);

            answer = len;
        }


        return answer * answer;
    }
};