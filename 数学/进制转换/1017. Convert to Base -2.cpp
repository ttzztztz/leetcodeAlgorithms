class Solution {
public:
    string baseNeg2(int n) {
        string ans;
        int carry = 0;
        while (n) {
            if (n & 1) ans += "1";
            else ans += "0";

            n = -(n >> 1);
        }
        
        reverse(ans.begin(), ans.end());
        if (ans.empty()) return "0";
        else return ans;
    }
};
