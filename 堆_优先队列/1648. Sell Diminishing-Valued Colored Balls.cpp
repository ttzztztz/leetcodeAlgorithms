class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        typedef long long ll;
        const int mod = 1e9+7;
        typedef pair<ll, ll> State;
        priority_queue<State, vector<State>, less<>> q;
        for (int i : inventory) q.emplace(i, 1);
        
        ll ans = 0;
        while (!q.empty()) {
            if (orders == 0) break;
            
            ll t;
            int cnt;
            tie(t, cnt) = q.top();
            q.pop();
            while (!q.empty() && q.top().first == t) cnt += q.top().second, q.pop();
            
            ll max_pick = t * cnt;
            if (!q.empty()) max_pick = min(max_pick, max(1ll, cnt * (t - q.top().first)));
            
            ll pick = min(max_pick, (ll) orders);
            orders -= pick;
            
            if (cnt == 1) {
                ans = (ans + (t + (t - pick + 1)) * pick / 2) % mod;
                if (t - pick > 0) q.emplace(t - pick, 1);
            } else {
                ll k = pick / cnt;
                const ll start = t;
                const ll end = min(start, t - k + 1);
                
                // cout << ans << endl;
                // cout << pick << ", " << cnt << ", " << t << ", " << start << ", " << end << endl;
                ans = (ans + cnt * (start + end) * k / 2) % mod;
                if (pick % cnt) {
                    const ll m = pick % cnt;
                    if (k > 0) ans = (ans + m * (end - 1)) % mod;
                    else if (k == 0) ans = (ans + m * end) % mod;
                    
                    // cout << m << ", " << end << endl;
                }
                
                if (t - k > 0 && cnt - (pick % cnt) > 0) q.emplace(t - k, cnt - (pick % cnt));
                if (t - k - 1 > 0 && pick % cnt > 0) q.emplace(t - k - 1, pick % cnt);
            }
            
        }
        
        return ans % mod;
    }
};
