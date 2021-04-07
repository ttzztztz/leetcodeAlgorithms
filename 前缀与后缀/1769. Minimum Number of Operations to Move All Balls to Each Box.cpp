class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.size();
        vector<int> ans(n);
        typedef pair<int, int> PII;

        vector<PII> f(n + 2), g(n + 2);
        for (int i = 1; i <= n; i++) {
            f[i] = {
                f[i - 1].first + (boxes[i - 1] == '1'), 
                f[i - 1].second + (boxes[i - 1] == '1') * (n - i)
            };
        }
        
        for (int i = n; i >= 1; i--) {
            g[i] = {
                g[i + 1].first + (boxes[i - 1] == '1'), 
                g[i + 1].second + (boxes[i - 1] == '1') * i
            };
        }
        
        for (int i = 1; i <= n; i++) {
            auto [l_cnt, l_dist] = f[i - 1];
            auto [r_cnt, r_dist] = g[i + 1];
            
            ans[i - 1] = (l_dist - l_cnt * (n - i)) + (r_dist - r_cnt * i);
        }
        return ans;
    }
};