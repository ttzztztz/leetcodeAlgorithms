class Solution {
public:
    int maxSizeSlices(vector<int>& arr) {
        const int N = arr.size();
        if (N == 3) {
            return max(arr[0], max(arr[1], arr[2]));
        }
        vector<int> data1(arr.begin(), arr.end() - 1), data2(arr.begin() + 1, arr.end());
        const int K = N / 3;
        
        return max(solve(data1, K), solve(data2, K));
    }
private:
    int solve(const vector<int>& arr, const int K) {
        const int N = arr.size();
        vector<vector<int>> f(N + 2, vector<int>(K + 1, 0));
        
        f[0][1] = arr[0];
        f[1][1] = max(arr[0], arr[1]);
        
        for (int i = 2; i < N; i++) {
            for (int j = 0; j <= K; j++) {
                f[i][j] = max(f[i][j], f[i - 1][j]);
                if (j >= 1) f[i][j] = max(f[i][j], f[i - 2][j - 1] + arr[i]);
            }
        }
        
        return f[N - 1][K];
    }
};
