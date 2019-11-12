class Solution {
public:
    vector<vector<string>> answer;
    int N;
    void generate_string(const vector<int>& map) {
        vector<string> oneAnswer;
        for (int i = 0; i < N; i++) {
            string current(N, '.');
            current[map[i]] = 'Q';
            oneAnswer.push_back(current);
        }
        answer.push_back(oneAnswer);
    }
    bool isConflict(const vector<int>& map, int n) {
        for (int i = 0; i < n; i++) {
            if (map[i] == map[n] || fabs(map[i] - map[n]) == fabs(i - n)) {
                return true;
            }
        }
        return false;
    }
    void dfs(vector<int>& map, int index) {
        if (index >= N) {
            generate_string(map);
            return;
        }

        for (int i = 0; i < N; i++) {
            map[index] = i;
            if (!isConflict(map, index)) {
                dfs(map, index + 1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<int> map(N, 0);
        dfs(map, 0);
        return answer;
    }
};