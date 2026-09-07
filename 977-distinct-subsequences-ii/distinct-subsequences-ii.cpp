#define ll long long
const ll mod = 1e9 + 7 ;


class Solution {
public:

    int distinctSubseqII(string s) {
        vector<int> end(26, 0);

        for (char c : s){
            ll total = 1;

            for (int i = 0 ; i < 26; i++){
                total += end[i];
            }

            end[c - 'a'] = total % mod;
        }


        ll ans = 0 ;
        for (int i = 0 ; i <  26; i++){
            ans += end[i] ;
        }

        return ans % mod;
    }
};