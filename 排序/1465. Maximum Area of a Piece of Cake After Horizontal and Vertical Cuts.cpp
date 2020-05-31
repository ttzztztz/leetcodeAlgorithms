class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        const int MOD = 1e9+7;
        
        ho.push_back(0);
        ho.push_back(h);
        
        ve.push_back(0);
        ve.push_back(w);
        
        const int N = ho.size(), M = ve.size();        
        long long mx1 = 0, mx2 = 0;
        sort(ho.begin(), ho.end());
        sort(ve.begin(), ve.end());
        
        for (int i = 1; i < N; i++) {
            mx1 = max(mx1, (long long) (ho[i] - ho[i - 1]));
        }
        for (int i = 1; i < M; i++) {
            mx2 = max(mx2, (long long) (ve[i] - ve[i - 1]));
        }
        
        return ((mx1 % MOD) * (mx2 % MOD)) % MOD;
    }
};
