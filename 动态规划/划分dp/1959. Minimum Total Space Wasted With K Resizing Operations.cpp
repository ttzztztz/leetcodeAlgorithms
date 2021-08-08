class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(f, 0xff, sizeof f);
        memset(mx, 0, sizeof mx);
        memset(psum, 0, sizeof psum);
        
        t = nums;
        n = t.size();
        
        for (int i = 0; i < n; i++) {
            if (i == 0) psum[i] = nums[i];
            else psum[i] = psum[i - 1] + nums[i];
            
            mx[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) mx[i][j] = max<ll>(mx[i][j - 1], nums[j]);
        }
        
        return dfs(0, k + 1);
    }
private:
    typedef long long ll;
    ll f[202][202], mx[202][202], psum[202];
    const ll maxn = 0x3f3f3f3f3f3f3f3f;
    vector<int> t;
    int n;
    
    ll sum(int l, int r) {
        ll u = psum[r];
        if (l >= 1) u -= psum[l - 1];
        return u;
    }
    
    ll dfs(int idx, int rest) {
        if (idx == n) return 0;
        ll& val = f[idx][rest];
        if (val != -1) return val;
        
        ll ans = maxn;
        for (int j = idx; j < n; j++) {
            const int len = j - idx + 1;
            ll cost = mx[idx][j] * len - sum(idx, j);
            if (rest >= 1) ans = min(ans, cost + dfs(j + 1, rest - 1));
        }
        return val = ans;
    }
};