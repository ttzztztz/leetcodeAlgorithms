class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        
        int f[1002];
        memset(f, 0, sizeof f);
        
        for (int i = n - 1; i >= 0; i--) {
            f[i] = cost[i] + min(f[i + 1], f[i + 2]);
        }
        return min(f[0], f[1]);
    }
};