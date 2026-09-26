class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

       // brute force ... 
       // odd len
        int max_odd_len = 0;
        string odd_palindrome = "";
        for (int i = 0 ; i < n; i++){
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]){
                l --;
                r ++;
            }

            max_odd_len = max(max_odd_len, r - l + 1);
            if (max_odd_len == r - l + 1){
                odd_palindrome = s.substr(l + 1, r - l - 1);
            }
       }


       // even len 
       int max_even_len = 0;
       string even_palindrome = "";

       for (int i = 0; i < n - 1 ; i++){
            if (s[i] != s[i+1])
                continue;
            int l = i;
            int r = i+1;

            while (l >= 0 && r < n && s[l] == s[r] ){
                l --;
                r ++;

            }

            max_even_len = max(max_even_len , r - l + 1);
            if (max_even_len == r - l + 1)
                even_palindrome = s.substr(l + 1 , r - l - 1);

       }

        return (max_odd_len > max_even_len) ? odd_palindrome : even_palindrome;
        
    }
};