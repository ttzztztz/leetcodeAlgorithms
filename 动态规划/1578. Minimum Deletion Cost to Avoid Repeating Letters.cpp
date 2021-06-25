class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if (s.empty()) return 0;
        
        const int n = cost.size();
        vector<int> f(27, numeric_limits<int>::max() / 2);
        
        for (int i = n; i >= 0; i--) {
            vector<int> g(27, numeric_limits<int>::max() / 2);
            for (int last = 0; last < 27; last++) {
                int& val = g[last];
                if (i == n) {
                    val = 0;
                    continue;
                }

                const int cur = s[i] - 'a';
                if (last == 26) {
                    val = min(f[26] + cost[i], f[cur]);
                    continue;
                }

                if (last == cur) {
                    val = cost[i] + f[last];
                } else {
                    val = min(cost[i] + f[last], f[cur]);
                }
            }
            f = g;
        }
        return f[26];
    }
};