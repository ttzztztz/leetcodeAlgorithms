class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = -1;
        const int n = baseCosts.size(), m = toppingCosts.size();
        for (int bc : baseCosts) {
            
            for (int s = 0; s < (1 << (2 * m)); s++) {
                int cur = bc;
                for (int i = 0; i < 2 * m; i++) {
                    if (s & (1 << i)) {
                        cur += toppingCosts[i % m];
                    }
                }
                
                if (ans == -1 || abs(ans - target) > abs(cur - target) || (abs(ans - target) == abs(cur - target) && cur < ans)) {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};
