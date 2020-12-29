class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> idx(26, vector<int>{});
        const int n = source.size(), m = target.size();
        for (int i = 0; i < n; i++) {
            const int d = source[i] - 'a';
            idx[d].push_back(i);
        }
        
        int ans = 0, s = 0;
        for (int t = 0; t < target.size(); t++) {
            const int d = target[t] - 'a';
            if (idx[d].empty()) return -1;
            
            auto it = lower_bound(idx[d].begin(), idx[d].end(), s);
            if (it == idx[d].end()) {
                ans++;
                s = idx[d][0] + 1;
            } else {
                s = *it + 1;
            }
        }
        return ans + (s != 0);
    }
};
