class Solution {
public:
    /**
     * @param E: the number of easy problems
     * @param EM: the number of "easy and medium" problems
     * @param M: the number of medium problems
     * @param MH: the number of "medium and hard" problems
     * @param H: the number of hard problems
     * @return: nothing
     */
    long long theNumberOfContests(long long E, long long EM, long long M, long long MH, long long H) {
        typedef long long ll;
        
        ll ans = 0;
        ll t = M + EM + MH;
        
        ll _a = (t - 2 * H + E) / 3;
        vector<ll> maybe_a = { _a, _a + 1, _a - 1, 0, MH };
        
        for (ll a : maybe_a) {
            ll _x = (t - E - a) / 2;
            vector<ll> maybe_x = { _x, _x + 1, _x - 1, 0, EM };
            for (ll x : maybe_x) {
                if (x < 0 || x > EM) continue;
                if (a < 0 || a > MH) continue;

                ans = max(ans, min(E + x, min(H + a, t - (x + a))));
            }
        }
        
        return ans;
    }
};
