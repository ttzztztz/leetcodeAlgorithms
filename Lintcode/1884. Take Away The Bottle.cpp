class Solution {
public:
    /**
     * @param arr: the array of bottles
     * @return: the minimum number of times you can take all the bottles
     */
    int takeAwayTheBottle(vector<int> &arr) {
        const int N = arr.size();
        
        vector<vector<int>> f(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < N; i++) f[i][i] = 1;
        for (int i = 0; i + 1 < N; i++) {
            if (arr[i] == arr[i + 1]) f[i][i + 1] = 1;
            else f[i][i + 1] = 2;
        }
        
        for (int len = 3; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                
                if (arr[i] == arr[j]) f[i][j] = f[i + 1][j - 1];
                else f[i][j] = min(1 + f[i][j - 1], 1 + f[i + 1][j]);
                
                for (int k = i; k + 1 <= j; k++) {
                    if (arr[i] == arr[k]) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        
        return f[0][N - 1];
    }
};
