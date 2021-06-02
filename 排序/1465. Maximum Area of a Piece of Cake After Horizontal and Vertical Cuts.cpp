class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        const int n = horizontalCuts.size(), m = verticalCuts.size();
        typedef long long ll;
        const int mod = 1e9+7;
        
        ll d1 = horizontalCuts[0];
        for (int i = 1 ; i < n; i++) d1 = max<ll>(d1, horizontalCuts[i] - horizontalCuts[i - 1]);
        d1 = max<ll>(d1, h - horizontalCuts[n - 1]);
        
        ll ans = verticalCuts[0] * d1;
        for (int i = 1; i < m; i++) ans = max<ll>(ans, d1 * (verticalCuts[i] - verticalCuts[i - 1]));
        ans = max<ll>(ans, d1 * (w - verticalCuts[m - 1]));
        return ans % mod;
    }
};