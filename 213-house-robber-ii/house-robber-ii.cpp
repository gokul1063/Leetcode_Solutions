class Solution {
public:
    int rob2(vector<int>& nums, int start, int end){
        int n = end - start + 1;

        if (n == 1) 
            return nums[start];

        vector<int> dp(n, 0);

        dp[0] = nums[start];

        dp[1] = max(nums[start + 1], nums[start]);

        for (int i = 2 ; i < n ; i++){
            dp[i] = max(
                dp[i-1],
                nums[start + i] + dp[i-2]
            );
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];
        return max(
            rob2(nums,0,n-2),
            rob2(nums,1,n-1)
        );
    }
};