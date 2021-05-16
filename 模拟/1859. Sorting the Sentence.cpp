class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> memo;
        int mx = 0;
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            else if ('0' <= s[i] && s[i] <= '9') {
                memo[s[i] - '0'] += tmp;
                mx = max(mx, s[i] - '0');
                tmp.clear();
            } else {
                tmp += s[i];
            }
        }
        
        string ans;
        for (int i = 1; i <= mx; i++) {
            ans += memo[i];
            if (i != mx) ans += ' ';
        }
        return ans;
    }
};