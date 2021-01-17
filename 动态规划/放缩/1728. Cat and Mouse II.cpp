class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        this->grid = grid, this->cj = catJump, this->mj = mouseJump;
        
        memset(f, 0xff, sizeof f);
        int mx = -1, my = -1, cx = -1, cy = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 'M') mx = i, my = j, grid[i][j] = '.';
                else if (grid[i][j] == 'C') cx = i, cy = j, grid[i][j] = '.';
                else if (grid[i][j] == 'F') fx = i, fy = j;
            }
        }
        
        return dfs(mx, my, cx, cy, 0);
    }
private:
    int f[8][8][8][8][200];
    vector<string> grid;
    int fx, fy, cj, mj;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] != '#';
    }
    
    // return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.
    int dfs(int mx, int my, int cx, int cy, int ttl) {
        int t = ttl % 2;
        if (mx == cx && my == cy) return false; // cat win
        if (ttl > 200) return false;
        int& val = f[mx][my][cx][cy][ttl];
        if (val != -1) return val;
        
        int ans;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        if (t == 0) { // mouse turn
            ans = 0;
            
            for (int k = 0; k < 4; k++) {
                for (int i = 0; i <= mj; i++) {
                    const int nx = mx + dx[k] * i, ny = my + dy[k] * i;
                    if (!point_valid(nx, ny)) break;
                    
                    if (nx == fx && ny == fy) return val = true;
                    if (dfs(nx, ny, cx, cy, ttl + 1) == true) return val = true;
                }
            }
        } else { // cat turn
            ans = 1;
            
            for (int k = 0; k < 4; k++) {
                for (int i = 0; i <= cj; i++) {
                    const int nx = cx + dx[k] * i, ny = cy + dy[k] * i;
                    if (!point_valid(nx, ny)) break;
                    
                    if (nx == fx && ny == fy) return val = false;
                    if (nx == mx && ny == my) return val = false;
                    if (dfs(mx, my, nx, ny, ttl + 1) == false) return val = false;
                }
            }
        }
        
        return val = ans;
    }
};
