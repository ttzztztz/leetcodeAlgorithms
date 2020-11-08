class Solution {
public:
    int maxProfit(vector<int>& inv, int orders) {
        this->inventory = inv;
        ll l = 0, r = *max_element(inventory.begin(), inventory.end());
        while (l <= r) {
            const ll mid = (l + r) >> 1;
            const ll f = solve(mid);
            
            if (f < orders) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        const ll v = r;
        // answer is r
        ll ans = 0, used = 0;
        for (int idx = inventory.size() - 1, cnt = 0; idx >= 0; idx--) {
            const ll i = inventory[idx];
            if (i >= v) {
                used += i - v;
                ans = (ans + (i + v + 1) * (i - v) / 2) % mod;
            }
        }
        
        ans = (ans + (orders - used) * (v + 1)) % mod;
        ans = (ans + mod) % mod;
        return ans;
    }
private:
    typedef long long ll;
    vector<int> inventory;
    const int mod = 1e9+7;
    
    ll solve(int num) {
        ll ans = 0;
        for (int i : inventory) {
            if (i >= num) ans += i - num;
        }
        return ans;
    }
};
