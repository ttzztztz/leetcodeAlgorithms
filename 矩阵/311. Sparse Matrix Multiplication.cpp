class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int n = A.size(), m = A[0].size(), k = B[0].size();
        vector<vector<int>> ans(n, vector<int>(k, 0));

        vector<vector<int>> a(n), b(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] != 0) a[i].emplace_back(j);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                if (B[i][j] != 0) b[j].emplace_back(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                // for (int x = 0; x < m; x++) {
                    // ans[i][j] += A[i][x] * B[x][j];
                // }
                
                int ptr1 = 0, ptr2 = 0;
                while (ptr1 < a[i].size() && ptr2 < b[j].size()) {
                    if (a[i][ptr1] == b[j][ptr2]) {
                        ans[i][j] += A[i][a[i][ptr1]] * B[b[j][ptr2]][j];
                        ptr1++, ptr2++;
                    } else if (a[i][ptr1] < b[j][ptr2]) {
                        ptr1++;
                    } else { // a[i][ptr1] > b[j][ptr2]
                        ptr2++;
                    }
                }
            }
        }
        return ans;
    }
};
