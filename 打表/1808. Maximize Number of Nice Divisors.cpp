class Solution {
public:
    int maxNiceDivisors(int n) {
        if (n == 1) return 1;
        
        ll ans = 0;
        if (n % 2 == 0) {
            const int t = n / 2;
            const ll k = t / 3, m = t % 3;
            // cout << t << "," << k << "," << m << endl;
            ans = (fpow(9, k) * fpow(2, m)) % mod;
        } else {
            const int t = n / 2;
            int k = t / 3, m = (t + 2) % 3;
            if (t % 3 == 0) k--;
            // cout << t << "," << k << "," << m << endl;
            ans = (((3ll * fpow(9, k)) % mod) * fpow(2, m)) % mod;
        }
        return ans % mod;
    }
private:
    const int mod = 1e9+7;
    typedef long long ll;
    ll fpow(ll a, ll b) {
        ll ans = 1, base = a;
        while (b > 0) {
            if (b & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }
};

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// ll f[1005];
// const int mod = 1e9+7;

// ll dfs(int n) {
//   if (n == 0) return 1;
//   ll& val = f[n];
//   if (val != -1) return val;
//   ll ans = 0;

//   for (int i = 1; i <= n; i++) {
//     ans = max(ans, dfs(n - i) * i);
//   }
//   return val = ans;
// }

// int main() {
//   memset(f, 0xff, sizeof f);
//   for (int i = 1; i <= 50; i++) {
//     cout << i << "," << dfs(i) << endl;
//   }
//   return 0;
// }
