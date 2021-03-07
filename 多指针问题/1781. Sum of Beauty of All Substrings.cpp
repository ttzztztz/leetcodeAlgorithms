class Solution {
public:
    int beautySum(string s) {
        const int n = s.size();
        int ans = 0;
        for (int l = 0; l < n; l++) {
            unordered_map<char, int> a;
            for (int r = l; r < n; r++) {
                a[s[r]]++;
                if (a.size() == 1) continue;
                int mi = 999999, ma = -1;
                for (auto& [k, v] : a) {
                    mi = min(mi, v);
                    ma = max(ma, v);
                }
                
                ans += ma - mi;
            }
        }
        return ans;
    }
};
