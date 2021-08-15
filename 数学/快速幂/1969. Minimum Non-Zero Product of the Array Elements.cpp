class Solution {
public:
    int minNonZeroProduct(int p) {
        ll ans = ((1ll << p) - 1 + mod) % mod;
        
        ll base = ((1ll << p) - 2 + mod) % mod;
        ll exp = (1ll << (p - 1)) - 1;
        
        // cout << base << "," << exp << endl;
        ans = (ans * fastpow(base, exp)) % mod;
        return ans;
    }
private:
    const int mod = 1e9+7;
    typedef long long ll;
    
    ll fastpow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
};