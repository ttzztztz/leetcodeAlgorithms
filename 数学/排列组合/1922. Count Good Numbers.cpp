class Solution {
public:
    int countGoodNumbers(long long n) {
        ll ans = 1;
        const ll b = n / 2;
        const ll a = n - b;
        
        ans = (ans * fast_pow(5, a)) % mod;
        ans = (ans * fast_pow(4, b)) % mod;
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    
    ll fast_pow(ll a, ll b) {
        ll ans = 1, base = a;
        while (b) {
            if (b & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }
};