class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        this->A = A;
        n = A.size();
        all_sum = accumulate(A.begin(), A.end(), 0);
        
        f = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(all_sum + 1, -1)));
        return dfs(0, 0, 0);
    }
private:
    vector<vector<vector<int>>> f;
    int n, all_sum = 0;
    vector<int> A;

    bool dfs(int i, int n1, int sum) {
        if (i == n) {
            if (n1 == 0 || n == n1) return false;
            return sum * (n - n1) == (all_sum - sum) * n1;
        }
        
        int& val = f[i][n1][sum];
        if (val != -1) return val;
        
        if (dfs(i + 1, n1 + 1, sum + A[i])) return val = true;
        if (dfs(i + 1, n1, sum)) return val = true;
        
        return val = false;
    }
};
