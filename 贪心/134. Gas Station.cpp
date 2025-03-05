class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int cur = 0, ans = 0, total_gas = 0, total_cost = 0;
        for (int i = 0; i < n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0) {
                ans = i + 1;
                cur = 0;
            }
        }

        if (total_gas < total_cost) return -1;
        return ans;
    }
};