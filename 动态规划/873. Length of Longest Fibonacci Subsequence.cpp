class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        const int n = A.size();
        unordered_map<int, int> appear;
        for (int i = 0; i < n; i++) appear[A[i]] = i;
        
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                const int v = A[i] + A[j];
                if (!appear.count(v)) continue;
                
                const int k = appear[v];
                memo[j][k] = max(memo[j][k], memo[i][j] + 1);
                ans = max(ans, memo[j][k] + 2);
            }
        }
        return ans;
    }
};
