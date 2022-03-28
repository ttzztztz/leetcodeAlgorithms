class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int f[2005][2005];
        vector<vector<int>> psum;
        memset(f, 0xff, sizeof f);
        
        const int n = piles.size();
        for (int i = 0; i < n; i++) {
            vector<int> p(piles[i].size() + 1, 0);
            for (int j = 1; j <= piles[i].size(); j++) {
                p[j] = p[j - 1] + piles[i][j - 1];
            }
            psum.push_back(p);
        }
        
        for (int idx = psum.size(); idx >= 0; idx--) for (int remain = k; remain >= 0; remain--) {
            int& val = f[idx][remain];
            if (idx == psum.size()) {
                val = 0;
                continue;
            }

            int ans = 0;
            for (int j = 0; j < psum[idx].size() && remain - j >= 0; j++) {
                // j: [remain, len]
                ans = max(ans, psum[idx][j] + f[idx + 1][remain - j]);
            }
            val = ans;
        }
        return f[0][k];
    }
};
