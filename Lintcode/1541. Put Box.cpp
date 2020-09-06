class Solution {
public:
    /**
     * @param box: the boxes
     * @param position: the positions
     * @return:  the maximum number of boxes you can put in
     */
    int putBox(vector<int> &box, vector<int> &position) {
        N = box.size(), M = position.size();
        f = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));
        return dfs(box, position, 0, 0);
    }
    int dfs(const vector<int> &box, const vector<int> &position, int i, int j) {
        if (i == N || j == M) return 0;
        if (f[i][j] != -1) return f[i][j];
        
        int answer = 0;
        if (box[i] <= position[j]) {
            answer = max(answer, 1 + dfs(box, position, i + 1, j + 1));
        }
        answer = max(answer, dfs(box, position, i, j + 1));
        answer = max(answer, dfs(box, position, i + 1, j));
        return f[i][j] = answer;
    }
private:
    vector<vector<int>> f;
    int N, M;
};
