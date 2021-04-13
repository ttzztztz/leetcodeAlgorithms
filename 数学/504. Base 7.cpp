class Solution {
public:
    string convertToBase7(int num) {
        string symbol = "";
        if (num < 0) {
            symbol = "-";
            num = -num;
        }
        string ans;
        while (num) {
            ans += to_string(num % 7);
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        
        if (ans.empty()) ans = "0";
        return symbol + ans;
    }
};
