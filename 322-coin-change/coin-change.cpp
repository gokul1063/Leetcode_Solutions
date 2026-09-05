class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<int> dp(amount + 1, 100000);

        dp[0] = 0;

        for (int i = 0 ; i <= amount ; i++){
            for (int coin : coins){
                if ((i - coin) >= 0){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        return (dp[amount] == 100000) ? -1 : dp[amount];
    }
};