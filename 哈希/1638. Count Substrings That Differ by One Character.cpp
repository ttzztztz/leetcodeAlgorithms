class Solution {
public:
    int countSubstrings(string s, string t) {
        unordered_map<string, int> ts;
        const int n = s.size(), m = t.size();
        
        for (int i = 0; i < m; i++) {
            for (int len = 1; i + len - 1 < m; len++) {
                ts[t.substr(i, len)]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int len = 1; i + len - 1 < n; len++) {
                ans += ok(ts, s, i, len);
            }
        }
        return ans;
    }
private:
    int ok(unordered_map<string, int>& ts, const string& tmp, int i, int len) {
        const int j = i + len - 1;
        string s = tmp.substr(i, len);
        
        int ans = 0;
        for (int a = 0; a < s.size(); a++) {
            for (int k = 'a'; k <= 'z'; k++) {
                if (s[a] == k) continue;
                
                const char prev = s[a];
                s[a] = k;
                if (ts.count(s)) ans += ts[s];
                s[a] = prev;
            }
        }
        
        return ans;
    }
};
