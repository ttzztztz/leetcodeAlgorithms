class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int inf = 1e9;
        int l = -inf, r = inf;
        while (l <= r) {
            const int mid = (l + r) / 2;
            const int t = solve(matrix, mid);
            
            if (t < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
    }
private:
    int solve(const vector<vector<int>>& mat, int target) {
        int ans = 0;
        const int n = mat.size(), m = mat[0].size();
        for (int i = 0, j = m - 1; i < n; i++) {
            while (j >= 0 && mat[i][j] > target) j--;
            ans += j + 1;
        }
        return ans;
    }
};