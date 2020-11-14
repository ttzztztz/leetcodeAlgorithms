class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        const int q = queries.size(), n = s.size();
        vector<bool> ans(q, false);
        vector<vector<int>> pref(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            const int ch = s[i] - 'a';
            pref[i + 1][ch] = pref[i][ch] + 1;
            
            for (int k = 0; k < 26; k++) {
                if (k == ch) continue;
                pref[i + 1][k] = pref[i][k];
            }
        }
        
        for (int i = 0; i < q; i++) {
            const int l = queries[i][0], r = queries[i][1], k = queries[i][2];
            
            int oddCnt = 0;
            for (int a = 0; a < 26; a++) {
                const int t = pref[r + 1][a] - pref[l][a];
                if (t % 2 == 1) oddCnt++;
            }
            
            if ((r - l + 1) % 2 == 0) {
                ans[i] = k >= oddCnt / 2;
            } else { // 1
                ans[i] = k >= (oddCnt - 1) / 2;
            }
        }
        return ans;
    }
};
