class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size(), sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            int s = 0;
            
            f[i][0] = numeric_limits<int>::min(), f[i][1] = numeric_limits<int>::max();
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                s += stoneValue[i + k - 1];
                f[i][0] = max(f[i][0], f[i + k][1] + s);
                f[i][1] = min(f[i][1], f[i + k][0]); // error
            }
        }
        
        if (f[0][0] > sum - f[0][0]) return "Alice";
        else if (f[0][0] < sum - f[0][0]) return "Bob";
        else return "Tie";
    }
};