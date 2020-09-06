class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for (const auto& p : prerequisites) {
            f[p[0]][p[1]] = true;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (f[i][k] && f[k][j]) f[i][j] = true;
                }
            }
        }
        
        vector<bool> answer;
        for (int i = 0; i < queries.size(); i++) {
            answer.push_back(f[queries[i][0]][queries[i][1]]);
        }
        return answer;
    }
};
