class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        ll l = 0, r = maxSum;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll ans = solve(mid, index, n);
            // cout << mid << "," << ans << endl;
            if (ans <= 1ll * maxSum) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // cout << endl;
        return r;
    }
private:
    typedef long long ll;
    ll solve(ll x, ll idx, ll n) {
        ll ans = x;
        const ll l = idx, r = n - idx - 1;
        // cout << "d " << l << ", " << r << endl;
        ans += calc(x, l - 1);
        // cout << "A " << calc(x, l - 1) << endl;
        ans += calc(x, r - 1);
        // cout << "B " << calc(x, r - 1) << endl;
        return ans;
    }
    
    ll calc(ll x, ll idx) {
        if (idx < 0) return 0;
        ll ans = 0;
        if (x - idx - 1 <= 0) {
            if (x - 1 <= 0) {
                ans += idx + 1;
            } else {
                // cout << idx << "," << x << "d" << endl;
                ans += idx - x + 2;
                ans += x * (x - 1) / 2;
            }
        } else {
            ans += (2 * x - idx - 2) * (idx + 1) / 2;
        }
        return ans;
    }
};
