class Solution {
public:

    int helper (string s, int l , int r){
        int count = 0;

        while (l >= 0 && r < s.length() && s[l] == s[r] ){
            count ++;
            l --;
            r ++;
        }

        return count;
    }

    int countSubstrings(string s) {
       int n = s.length();

       int res = 0;
       for (int i = 0; i < n; i++){

            res +=  helper(s, i , i);
            if (i != n -1)
                if (s[i] == s[i+1])
                    res += helper(s, i , i+1);

       } 

       return res;
    }
};