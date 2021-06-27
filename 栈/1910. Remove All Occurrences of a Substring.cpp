class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        const int n = s.size(), m = part.size();
        for (int i = 0; i < n; i++) {
            ans += s[i];
            while (ans.size() >= m && ans.substr(ans.size() - m, m) == part) {
                for (int j = 0; j < m; j++) ans.pop_back();
            }
        }
        return ans;
    }
};