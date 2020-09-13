class Solution {
public:
    /**
     * @param boxes: List[int]
     * @return: return an integer
     */
    int removeBoxes(vector<int> &boxes) {
        // write your code here
        this->b = boxes;
        n = boxes.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(0, n - 1, 0);
    }
private:
    vector<int> b;
    int n;
    int f[105][105][105];
    
    int dfs(int i, int j, int k) {
        if (i == j) return (k + 1) * (k + 1);
        if (i > j) return 0;
        
        int& val = f[i][j][k];
        if (val != -1) return val;
        
        int answer = dfs(i, j - 1, 0) + (k + 1) * (k + 1);
        for (int m = i; m + 1 <= j; m++) {
            if (b[j] == b[m]) {
                answer = max(answer, dfs(i, m, k + 1) + dfs(m + 1, j - 1, 0));
            }
        }
        return val = answer;
    }
};
