class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string stk;
        for (int i = 0; i < s.size(); i++) {
            if (x < y) { // remove ba
                if (s[i] == 'a' && !stk.empty() && stk.back() == 'b') {
                    stk.pop_back();
                    ans += y;
                } else {
                    stk += s[i];
                }
            } else { // remove ab
                if (s[i] == 'b' && !stk.empty() && stk.back() == 'a') {
                    stk.pop_back();
                    ans += x;
                } else {
                    stk += s[i];
                }
            }
        }
        
        s = stk;
        stk.clear();
        
        for (int i = 0; i < s.size(); i++) {
            if (x < y) { // remove ab
                if (s[i] == 'b' && !stk.empty() && stk.back() == 'a') {
                    stk.pop_back();
                    ans += x;
                } else {
                    stk += s[i];
                }
            } else { // remove ba
                if (s[i] == 'a' && !stk.empty() && stk.back() == 'b') {
                    stk.pop_back();
                    ans += y;
                } else {
                    stk += s[i];
                }
            }
        }
        
        return ans;
    }
};
