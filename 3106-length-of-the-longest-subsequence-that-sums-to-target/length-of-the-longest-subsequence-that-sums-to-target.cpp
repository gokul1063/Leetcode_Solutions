// dp method 
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        const int inf = -1e9;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target+1, 0));

        for (int j = 1 ; j <= target ; j++){
            dp[0][j] = inf;
        }

        for (int i = 1 ; i < nums.size() + 1; i++){
            for (int j = 1 ; j < target + 1 ; j++){
                int t1 = dp[i-1][j];
                int t2 = inf;
                if (nums[i-1] <= j)
                    t2 = dp[i-1][j-nums[i-1]] + 1;
                dp[i][j] = max(
                        t1, t2
                );

            }
        }

        return dp[nums.size()][target] >= 0 ? dp[nums.size()][target] : -1; 
    }
};