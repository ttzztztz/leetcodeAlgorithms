class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ll l = 1, r = 1e5 + 1;
        while (l <= r) {
            const ll mid = (l + r) / 2;
            
            const ll t = solve(mid);
            if (t < neededApples) l = mid + 1;
            else if (t == neededApples) return 8 * mid;
            else r = mid - 1;
        }
        return 8 * l;
    }
private:
    typedef long long ll;
    
    ll solve(ll r) {
        ll ans = 0;
        for (ll i = 1; i <= r; i++) ans += 4ll * i * i;
        for (ll i = 1; i <= r; i++) ans += 4ll * i * (2 * r - i + 1);
        return ans;
    }
};