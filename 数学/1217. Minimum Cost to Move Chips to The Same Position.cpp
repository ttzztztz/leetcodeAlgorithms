class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        typedef long long ll;
        ll ans = numeric_limits<ll>::max();
        const int n = position.size();
        
        for (int i = 0; i < n; i++) {
            const ll k = position[i];
            ll cur = 0;
            
            for (int j : position) {
                const ll d = abs(k - j);
                cur += (d % 2);
            }
            
            ans = min(ans, cur);
        }
        
        return ans;
    }
};
