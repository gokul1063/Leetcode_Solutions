class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> count(26,0);

       int left = 0, max_freq = 0, res = 0;

       for (int right = 0 ; right < s.length(); right ++){
            count[s[right] -'A']++;

            max_freq = max(max_freq, count[s[right] - 'A']);
            int window_size = (right - left + 1);
            while (window_size - max_freq > k){
                count[s[left] - 'A'] --;
                left ++;
                window_size = right - left + 1;
            }
            res = max(res, window_size);
       }
       return res;
    }
};