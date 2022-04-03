class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        typedef long long ll;
        ll l = 0, r = *max_element(candies.begin(), candies.end());
        
        auto solve = [&](ll e) -> ll {
            if (e == 0) return numeric_limits<ll>::max();
            
            ll ans = 0;
            for (ll v : candies) {
                const ll x = v / e, r = v % e;
                ans += x;
            }
            return ans;
        };
        
        while (l <= r) {
            const ll m = (l + r) >> 1;
            
            if (solve(m) < k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
