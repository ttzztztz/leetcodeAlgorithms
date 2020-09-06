class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        
        const int N = board.size(), M = board[0].size();
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == '.') continue;
                if ((j >= 1 && board[i][j - 1] == 'X') || (i >= 1 && board[i - 1][j] == 'X')) continue;
                
                answer++;
            }
        }
        return answer;
    }
};
