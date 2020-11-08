class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        memset(data, 0, sizeof data);
        
        ll ans = 0;
        for (int i : instructions) {
            const ll f = query(i - 1);
            const ll g = query(100000) - query(i);
            
            ans = (ans + min(f, g)) % mod;
            inc(i, 1);
        }
        
        return ans % mod;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    ll data[100005];
    ll lowbit(int x) {
        return x&(-x);
    }
    ll query(int u) {
        ll ans = 0;
        while (u) {
            ans = (ans + data[u]) % mod;
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int v) {
        while (u && u <= 100000) {
            data[u] = (data[u] + v) % mod;
            u += lowbit(u);
        }
    }
};
