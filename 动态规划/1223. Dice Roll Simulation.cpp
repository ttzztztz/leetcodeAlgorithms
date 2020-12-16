class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memo_ = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(6, vector<ll>(16, -1)));
        rollMax_ = rollMax;
        n_ = n;
        
        ll ans = 0;
        for (int i = 0; i <= 5; i++) {
            ans = (ans + dfs(1, i, 1)) % kMod;
        }
        return ans;
    }
private:
    typedef long long ll;
    vector<vector<vector<ll>>> memo_;
    vector<int> rollMax_;
    const int kMod = 1e9+7;
    int n_;
    
    ll dfs(int idx, int last, int consecutive) {
        if (idx == n_) return 1;
        ll& val = memo_[idx][last][consecutive];
        if (val != -1) return val;
        
        ll ans = 0;
        
        for (int k = 0; k <= 5; k++) {
            if (k != last) ans = (ans + dfs(idx + 1, k, 1)) % kMod;
            else {
                if (consecutive + 1 <= rollMax_[k]) ans = (ans + dfs(idx + 1, last, consecutive + 1)) % kMod;
            }
        }
        
        return val = ans;
    }
};
