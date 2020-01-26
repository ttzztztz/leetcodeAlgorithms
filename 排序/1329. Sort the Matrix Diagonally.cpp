class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int N = mat.size(), M = mat[0].size();
        
        unordered_set<int> visited;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                const int diag = j - i;
                if (visited.count(diag)) continue;
                visited.insert(diag);
                
                vector<int> all;
                for (int k = 0; i + k < N && j + k < M; k++) {
                    all.push_back(mat[i + k][j + k]);
                }
                sort(all.begin(), all.end());
                for (int k = 0; i + k < N && j + k < M; k++) {
                    mat[i + k][j + k] = all[k];
                }
            }
        }
        
        return mat;
    }
};
