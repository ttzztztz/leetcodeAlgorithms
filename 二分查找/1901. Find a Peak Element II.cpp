class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        const int n = mat.size(), m = mat[0].size();
        
        int l = 0, r = n - 1;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            
            const int j = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            int lasti = mid;
            if (mid >= 1 && mat[mid - 1][j] > mat[mid][j]) lasti = mid - 1;
            if (mid + 1 < n && mat[mid + 1][j] > mat[mid][j]) lasti = mid + 1;
            
            if (lasti == mid) return { mid, j };
            else if (lasti == mid - 1) r = mid - 1;
            else l = mid + 1; // lasti == mid + 1
        }
        return {};
    }
};