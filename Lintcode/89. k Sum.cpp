class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        this->A = A, this->n = A.size();
        f = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(target + 1, vector<int>(k + 1, -1)));
        
        return dfs(0, target, k);
    }
private:
    vector<int> A;
    int n;
    vector<vector<vector<int>>> f;
    
    int dfs(int i, int target, int k) {
        if (target < 0 || k < 0) return 0;
        if (target == 0) return k == 0 ? 1 : 0;
        if (i == n) return 0;
        
        int& val = f[i][target][k];
        if (val != -1) return val;
        int ans = 0;
        
        // select
        ans += dfs(i + 1, target - A[i], k - 1);
        ans += dfs(i + 1, target, k);
        
        return val = ans;
    }
};
