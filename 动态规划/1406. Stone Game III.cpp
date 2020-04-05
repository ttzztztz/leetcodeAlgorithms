class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        for (int i : stoneValue) sum += i;
        
        const int N = stoneValue.size();
        f = vector<vector<int>>(N + 5, vector<int>(2, -1));
        
        int answer = dfs(stoneValue, 0, 0);
        
        if (answer > sum - answer) return "Alice";
        else if (answer < sum - answer) return "Bob";
        else return "Tie";
    }
private:
    int sum = 0;
    vector<vector<int>> f;
    int dfs(const vector<int>& stoneValue, int i, int j) {
        if (i == stoneValue.size()) return 0;
        if (f[i][j] != -1) return f[i][j];
        
        int answer;
        if (j == 0) { // Alice turn
            answer = -99999999;
            int sum = 0;
            for (int k = 0; k < 3 && i + k < stoneValue.size(); k++) {
                sum += stoneValue[i + k];
                answer = max(answer, sum + dfs(stoneValue, i + k + 1, j ^ 1));
            }
        } else { // Bob turn
            answer = 99999999;
            for (int k = 0; k < 3 && i + k < stoneValue.size(); k++) {
                answer = min(answer, dfs(stoneValue, i + k + 1, j ^ 1));
            }
        }
        
        return f[i][j] = answer;
    }
};
