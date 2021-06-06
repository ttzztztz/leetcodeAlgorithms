class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        if (mat == target) return true;
        for (int i = 0; i < 4; i++) {
            rotate(mat);
            if (mat == target) return true;
        }
        return false;
    }
private:
    int n;
    void rotate(vector<vector<int>>& mat) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};