class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1)
            return s;
        vector<string> data(numRows, "");
        int ind = 0;
        int sign = 1;

        for (char ele : s) {
            if (ind == numRows - 1){
                sign = -1;
            }
            if (ind == 0){
                sign = +1;
            }   

            data[ind] = data[ind] + ele;
            ind += sign; 
        }

        string ans = "";
        for (string ele : data){
            ans += ele;
        }

        return ans;

    }
};