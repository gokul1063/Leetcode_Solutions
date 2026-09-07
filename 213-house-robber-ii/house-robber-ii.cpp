class Solution {
public:
    int helper(int start, int end, int offset, vector<int>& nums){
        int n = end - start + 1;
        vector<int> dp(n + 1, 0);

        dp[1] = nums[start];

        for (int i = 2 ; i <= n ; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i - 1]);
        } 

        return dp[n];


    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n1 = helper(0,nums.size()-2, 0, nums);
        int n2 = helper(1,nums.size()-1, 1, nums);

        return max(n1,n2);

    }
};