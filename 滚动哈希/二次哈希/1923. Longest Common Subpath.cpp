class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        init();
        
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
    const ll mod1 = 1e9+7, mod2 = 1e9+9;
    ll seed1, seed2;
    ll frac1[100005], frac2[100005];
    
    struct pair_hash {
        size_t operator()(const pair<ll, ll>& t) const {
            return (t.first << 16) | (t.second);
        }
    };
    
    void init() {
        memset(frac1, 0, sizeof frac1);
        memset(frac2, 0, sizeof frac2);
        
        mt19937 rd{ random_device{}() };
        auto distribution = uniform_int_distribution<int>(1e6, 1e7);
        seed1 = distribution(rd), seed2 = distribution(rd);
        
        frac1[0] = frac2[0] = 1;
        for (int i = 1; i <= 100000; i++) {
            frac1[i] = (frac1[i - 1] * seed1) % mod1;
            frac2[i] = (frac2[i - 1] * seed2) % mod2;
        }
    }
    
    bool solve(const vector<vector<int>>& paths, int len) {
        unordered_set<pair<ll, ll>, pair_hash> s1;
        for (int p = 0; p < paths.size(); p++) {
            auto& path = paths[p];
            const int n = path.size();
            
            unordered_set<pair<ll, ll>, pair_hash> s2;
            ll h1 = 0, h2 = 0;
            for (int i = 0; i < len; i++) {
                if (i >= n) return false;

                h1 = (h1 * seed1) % mod1;
                h1 = (h1 + path[i]) % mod1;
                
                h2 = (h2 * seed2) % mod2;
                h2 = (h2 + path[i]) % mod2;
            }
            
            if (p == 0 || s1.count({ h1, h2 })) {
                s2.emplace(h1, h2);
            }
            
            for (int l = 0, r = len; r < n; l++, r++) {
                h1 = ((h1 - frac1[len - 1] * path[l]) % mod1 + mod1) % mod1;
                h1 = (h1 * seed1) % mod1;
                h1 = (h1 + path[r]) % mod1;
                
                h2 = ((h2 - frac2[len - 1] * path[l]) % mod2 + mod2) % mod2;
                h2 = (h2 * seed2) % mod2;
                h2 = (h2 + path[r]) % mod2;
                
                if (p == 0 || s1.count({ h1, h2 })) {
                    s2.emplace(h1, h2);
                }
            }
            
            s1 = move(s2);
        }
        
        return !s1.empty();
    }
};