class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        f = vector<vector<vector<int>>>(2, vector<vector<int>>(205, vector<int>(105, -1)));
        return dfs(piles, 0, 1, 0);
    }
private:
    vector<vector<vector<int>>> f;
    int dfs(vector<int>& piles, int turn, int M, int i) {
        if (i >= piles.size()) return 0;
        if (f[turn][M][i] != -1) return f[turn][M][i];
        
        int answer;
        if (turn == 0) { // Alex
            answer = 0;
            int sum = 0;
            for (int j = 0; i + j < piles.size() && j < 2 * M; j++) {
                sum += piles[i + j];
                answer = max(answer, sum + dfs(piles, turn ^ 1, max(M, j + 1), i + j + 1));
            }
        } else { // Lee
            answer = 9999999;
            int sum = 0;
            for (int j = 0; i + j < piles.size() && j < 2 * M; j++) {
                sum += piles[i + j];
                answer = min(answer, dfs(piles, turn ^ 1, max(M, j + 1), i + j + 1));
            }
        }
        
        return f[turn][M][i] = answer;
    }
};
