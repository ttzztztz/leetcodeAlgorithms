class Solution {
public:
    int N, M;
    vector<vector<int>> dp;
    int dfs(const vector<vector<char>>& seats, int row, int last_mask) {
        if (row == N) return 0;
        if (dp[last_mask][row] != -1) return dp[last_mask][row];
        
        int answer = 0;
        for (int i = 0; i < (1 << M); i++) {
            if (!mask_valid(seats, i, row)) continue;
            if (!two_row_valid(seats, last_mask, i)) continue;
            
            answer = max(answer, _0_count(i) + dfs(seats, row + 1, i));
        }
        return dp[last_mask][row] = answer;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int answer = 0;
        N = seats.size(), M = seats[0].size();
        dp = vector<vector<int>>((1 << M) + 5, vector<int>(N + 5, -1));
        
        for (int i = 0; i < (1 << M); i++) {
            if (!mask_valid(seats, i, 0)) continue;
            
            answer = max(answer, _0_count(i) + dfs(seats, 1, i));
        }
        return answer;
    }
private:
    int _0_count(int mask) {
        int answer = 0;
        while (mask) {
            answer++;
            mask -= mask & (-mask);
        }
        return answer;
    }
    bool mask_valid(const vector<vector<char>>& seats, int mask, int col) {
        for (int i = 0; i < M; i++) {
            if (!(mask & (1 << i))) continue;
            
            if (seats[col][i] == '#') return false;
            if (i - 1 >= 0 && (mask & (1 << (i - 1)))) return false;
            if (i + 1 < M && (mask & (1 << (i + 1)))) return false;
        }
        return true;
    }
    bool two_row_valid(const vector<vector<char>>& seats, int prev, int cur) {
        for (int i = 0; i < M; i++) {
            if (!(cur & (1 << i))) continue;
            
            if (i - 1 >= 0 && (prev & (1 << (i - 1)))) return false;
            if (i + 1 < M && (prev & (1 << (i + 1)))) return false;
        }
        
        return true;
    }
};
