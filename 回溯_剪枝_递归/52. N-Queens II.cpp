class Solution {
public:
    int answer, N;
    bool isConflict(vector<int>& map, int n) {
        for (int i = 0; i < n; i++) {
            if (map[i] == map[n] || fabs(map[i] - map[n]) == fabs(i - n)) {
                return true;
            }
        }
        return false;
    }
    void dfs(vector<int>& map, int index) {
        if (index >= N) {
            answer++;
            return;
        }

        for (int i = 0; i < N; i++) {
            map[index] = i;
            if (!isConflict(map, index)) {
                dfs(map, index + 1);
            }
        }
    }
    int totalNQueens(int n) {
        answer = 0, N = n;
        vector<int> map(N, 0);

        dfs(map, 0);
        return answer;
    }
};