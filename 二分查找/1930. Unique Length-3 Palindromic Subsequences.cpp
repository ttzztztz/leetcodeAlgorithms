class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int inf = numeric_limits<int>::max() / 2, n = s.size();
        vector<int> mi(26, inf), ma(26, -inf);
        vector<vector<int>> idx(26);
        
        for (int i = 0; i < n; i++) {
            const int d = s[i] - 'a';
            
            idx[d].push_back(i);
            mi[d] = min(mi[d], i);
            ma[d] = max(ma[d], i);
        }
        
        int ans = 0;
        for (int head = 0; head < 26; head++) {
            if (idx[head].size() >= 3) ans++;
            if (idx[head].size() <= 1) continue;
            
            for (int middle = 0; middle < 26; middle++) {
                if (middle == head) continue;
                
                auto it = lower_bound(idx[middle].begin(), idx[middle].end(), mi[head]);
                if (it != idx[middle].end() && *it < ma[head]) ans++;
            }
        }
        return ans;
    }
};