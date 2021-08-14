class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        this->boxes = boxes;
        n = boxes.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(0, n - 1, 0);
    }
private:
    int n;
    vector<int> boxes;
    int f[101][101][101];
    
    int dfs(int i, int j, int k) {
        if (i == j) return (k + 1) * (k + 1);
        if (i > j) return 0;
        int& val = f[i][j][k];
        if (val != -1) return val;
        
        int ans = (k + 1) * (k + 1) + dfs(i, j - 1, 0);
        for (int p = i; p < j; p++) {
            if (boxes[p] == boxes[j]) {
                ans = max(ans, dfs(i, p, k + 1) + dfs(p + 1, j - 1, 0));
            }
        }
        return val = ans;
    }
};
