class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int> f(20001, 0);
        for (int i : baseCosts) {
            f[i] = 1;
        }
        
        for (int i = 0, len = toppingCosts.size(); i < len; i++) {
            toppingCosts.push_back(toppingCosts[i]);
        }

        for (int cost : toppingCosts) {
            for (int j = 20000; j >= cost; j--) {
                f[j] |= f[j - cost];
            }
        }
        
        int ans = -1;
        for (int i = 1; i <= 20000; i++) {
            if (f[i] && (ans == -1 || abs(ans - target) > abs(i - target))) {
                ans = i;
            }
        }
        return ans;
    }
};
