class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int mod = 1e9+7;
        typedef pair<int, int> pii;
        set<pii> buy, sell;
        typedef long long ll;
        ll ans = 0;
        
        for (auto& o : orders) {
            int p = o[0], a = o[1], t = o[2];
            if (t == 0) { // buy
                while (a > 0 && !sell.empty()) {
                    auto [price, amount] = *sell.begin();
                    if (price <= p) {
                        const int consume = min(a, amount);
                        a -= consume;
                        ans -= amount;
                        amount -= consume;
                        
                        sell.erase(sell.begin());
                        if (amount > 0) {
                            ans += amount;
                            sell.emplace(price, amount);
                        }
                    } else {
                        break;
                    }
                }
                
                if (a > 0) {
                    ans += a;
                    buy.emplace(p, a);
                }
            } else { // sell
                while (a > 0 && !buy.empty()) {
                    auto [price, amount] = *(--buy.end());
                    if (price >= p) {
                        const int consume = min(a, amount);
                        a -= consume;
                        ans -= amount;
                        amount -= consume;
                        
                        buy.erase(--buy.end());
                        if (amount > 0) {
                            ans += amount;
                            buy.emplace(price, amount);
                        }
                    } else {
                        break;
                    }
                }
                
                if (a > 0) {
                    ans += a;
                    sell.emplace(p, a);
                }
            }
        }
        
        return ans % mod;
    }
};
