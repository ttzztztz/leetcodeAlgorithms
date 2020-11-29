class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        this->A = A;

        unordered_set<ll> appear(A.begin(), A.end());
        const int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (appear.count(1ll * A[i] * A[j])) v[1ll * A[i] * A[j]].emplace_back(i, j);
            }
        }
        
        f = vector<ll>(n + 1, -1);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + dfs(i)) % mod;
        }
        return ans;
    }
private:
    typedef long long ll;
    typedef pair<ll, ll> PII;
    unordered_map<ll, vector<PII>> v;
    const int mod = 1e9+7;
    
    vector<int> A;
    vector<ll> f;

    ll dfs(int i) {
        if (f[i] != -1) return f[i];
        ll& val = f[i];

        ll ans = 1;
        for (auto [l, r] : v[A[i]]) {
            if (l == r) {
                ans = (ans + dfs(l) * dfs(l)) % mod;
            } else {
                ans = (ans + dfs(l) * dfs(r) * 2) % mod;
            }
        }
        return val = ans;
    }
};
