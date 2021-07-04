class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        init_frac();
        
        int l = 1, r = 100000;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (solve(paths, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
private:
    typedef long long ll;
    const ll mod = 1e11+19;
    const ll seed = 1e5+1;
    ll frac[100005];
    
    void init_frac() {
        memset(frac, 0, sizeof frac);
        frac[0] = 1;
        for (int i = 1; i <= 100000; i++) {
            frac[i] = (frac[i - 1] * seed) % mod;
        }
    }
    
    bool solve(const vector<vector<int>>& paths, int len) {
        unordered_map<ll, int> cnt;
        for (auto& path : paths) {
            const int n = path.size();
            
            unordered_set<ll> used;
            ll hash = 0;
            for (int i = 0; i < len; i++) {
                if (i >= n) return false;

                hash = (hash * seed) % mod;
                hash = (hash + path[i]) % mod;
            }
            used.insert(hash);
            cnt[hash]++;
            
            for (int l = 0, r = len; r < n; l++, r++) {
                hash = ((hash - frac[len - 1] * path[l]) % mod + mod) % mod;
                hash = (hash * seed) % mod;
                hash = (hash + path[r]) % mod;
                
                if (!used.count(hash)) {
                    used.insert(hash);
                    cnt[hash]++;
                }
            }
        }
        
        for (auto& [k, v] : cnt) {
            if (v == paths.size()) return true;
        }
        return false;
    }
};