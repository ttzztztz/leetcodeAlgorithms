int f[500005][5];

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        memset(f, 0xff, sizeof f);
        dict['a'] = 0;
        dict['e'] = 1;
        dict['i'] = 2;
        dict['o'] = 3;
        dict['u'] = 4;
        
        int ans = 0;
        this->n = word.size();
        this->w = word;
        
        for (int idx = n; idx >= 0; idx--) {
            for (int last = 0; last <= 4; last++) {
                if (idx == n) {
                    f[idx][last] = (last == 4) ? 0 : -9999999;
                    continue;
                }
                
                int& val = f[idx][last];

                int ans = -9999999;
                const char cur = w[idx];
                const int ord = dict[cur];
                if (last == 4) ans = 0;

                if (ord == last || last + 1 == ord) {
                    ans = max(ans, 1 + f[idx + 1][ord]);
                }
                val = ans;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (w[i] == 'a') ans = max(ans, 1 + f[i + 1][0]);
        }
        return ans;
    }
private:
    unordered_map<char, int> dict;
    string w;
    int n;
};