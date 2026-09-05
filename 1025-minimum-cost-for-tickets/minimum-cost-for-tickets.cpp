class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int max_days = days.back();
        vector<int> dp(max_days + 1, 0);

        int current_day_ind = 0;

        for (int i = 1; i <= max_days; i++) {

            if (current_day_ind >= days.size())
                break;

            if (i > days[current_day_ind])
                current_day_ind++;

            if (current_day_ind >= days.size())
                break;

            if (i == days[current_day_ind]) {

                int cost_min = dp[i - 1] + costs[0];

                cost_min = min(cost_min,
                               dp[max(0, i - 7)] + costs[1]);

                cost_min = min(cost_min,
                               dp[max(0, i - 30)] + costs[2]);

                dp[i] = cost_min;

            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[max_days];
    }
};