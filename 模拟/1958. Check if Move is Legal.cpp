const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        b = board;
        
        for (int k = 0; k < 8; k++) {
            if (dfs(rMove, cMove, k, color, 1)) return true;
        }
        
        return false;
    }
private:
    unordered_map<char, char> opposite_color = {
        {'B', 'W'}, {'W', 'B'}
    };
    
    int n = 8;
    vector<vector<char>> b;
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    
    bool dfs(int i, int j, int dir, char color, int len) {
        if (!point_valid(i, j)) return false;
        if (color == b[i][j]) {
            return len >= 3;
        }
        
        const int nx = i + dx[dir], ny = j + dy[dir];
        if (point_valid(nx, ny) && b[nx][ny] != '.' && dfs(nx, ny, dir, color, len + 1)) return true;
        return false;
    }
};