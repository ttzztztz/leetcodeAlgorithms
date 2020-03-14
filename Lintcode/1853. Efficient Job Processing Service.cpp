class Solution {
public:
    int maxWeight(int n, vector<int> &weights, vector<int> &tasks, int p) {
        vector<int> f(p + 5, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = p; j >= 2 * tasks[i]; j--) {
                f[j] = max(f[j], f[j - 2 * tasks[i]] + weights[i]);
            }
        }
        
        return f[p];
    }
};
