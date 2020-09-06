class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        
        vector<int> f(N, -99999999);
        for (int i = N - 1; i >= 0; i--) {
            for (int take = 0, k = 0; k < 3 && i + k <= N - 1; k++) {
                take += stoneValue[i + k];
                if (i + k + 1 < N) f[i] = max(f[i], take - f[i + k + 1]);
                else f[i] = max(f[i], take);
            }
        }
        
        if (f[0] > 0) return "Alice";
        else if (f[0] < 0) return "Bob";
        else return "Tie";
    }
};
