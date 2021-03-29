class Solution {
public:
    int maxNiceDivisors(int n) {
        if (n <= 2) return n;
        const int r = n % 3;
        
        ll ans = 0;
        if (r == 0) {
            return fpow(3, n / 3);
        } else if (r == 1) {
            return (fpow(3, n / 3 - 1) * 4ll) % mod;
        } else { // r == 2
            return (fpow(3, n / 3) * 2ll) % mod;
        }
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    
    ll fpow(ll a, ll b) {
        ll ans = 1, base = a;
        while (b) {
            if (b & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans % mod;
    }
};
