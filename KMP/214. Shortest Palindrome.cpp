class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
        const int n = s.size();
        vector<int> nxt = build_nxt(s);
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        int i = 0, j = 0;
        while (i < n) {
            if (j == -1 || s[j] == rev[i]) {
                i++, j++;
            } else {
                j = nxt[j];
            }
        }

        string ans = s.substr(j);
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
private:
    vector<int> build_nxt(const string& s) {
        const int n = s.size();
        vector<int> nxt(n + 1, 0);
        nxt[0] = -1;
        nxt[1] = 0;
        
        int i = 1, j = 0;
        while (i < n) {
            if (j == -1 || s[i] == s[j]) {
                nxt[++i] = ++j;
            } else {
                j = nxt[j];
            }
        }
        
        return nxt;
    }
};