class Solution {
public:
    int longestBeautifulSubstring(string word) {
        dict['a'] = 0;
        dict['e'] = 1;
        dict['i'] = 2;
        dict['o'] = 3;
        dict['u'] = 4;

        int ans = 0;
        this->n = word.size();
        this->w = word;
        
        vector<int> f(5, 0);
        for (int idx = n; idx >= 0; idx--) {
            vector<int> g(5, 0);
            for (int last = 0; last <= 4; last++) {
                if (idx == n) {
                    g[last] = (last == 4) ? 0 : -9999999;
                    continue;
                }

                int& val = g[last];

                int ans = -9999999;
                const char cur = w[idx];
                const int ord = dict[cur];
                if (last == 4) ans = 0;

                if (ord == last || last + 1 == ord) {
                    ans = max(ans, 1 + f[ord]);
                }
                val = ans;
            }
            f = g;
            if (idx < n && w[idx] == 'a') ans = max(ans, f[0]);
        }
        return ans;
    }
private:
    unordered_map<char, int> dict;
    string w;
    int n;
};