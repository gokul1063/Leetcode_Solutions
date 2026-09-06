class Solution {
public:
    int convertTime1(std::string current, std::string correct) {
        int curr_hour = std::stoi(current.substr(0, 2));
        int curr_min  = std::stoi(current.substr(3, 2));
        
        int corr_hour = std::stoi(correct.substr(0, 2));
        int corr_min  = std::stoi(correct.substr(3, 2));
        
        int current_total_minutes = (curr_hour * 60) + curr_min;
        int correct_total_minutes = (corr_hour * 60) + corr_min;
        
        int balance = correct_total_minutes - current_total_minutes;
        
        if (balance < 0) {
            balance += 24 * 60; 
        }
        
        return balance;
    }


    int convertTime(string current, string correct) {
        int balance = convertTime1(current, correct);


        vector<int> dp (balance + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= balance ; i++){
            int o = dp[i-1] + 1;
            int f = 1000000000;
            if (i >= 5) 
                f = dp[i-5] + 1;
            int ff = 1000000000;
            if (i >= 15)
                ff = dp[i-15] + 1;
            int s = 1000000;
            if (i >= 60)
                s = dp[i-60] + 1;
            dp[i] = min({o,f,ff,s});

        }
        return dp[balance];



    }
};