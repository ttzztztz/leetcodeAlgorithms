class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        this->arr = grid;
        n = grid.size(), m = grid[0].size();
        memset(visited, 0, sizeof visited);

        for (int i = 0; i < min(n, m); i++) {
            if (visited[i][i]) break;
            tmp.clear();
            points.clear();
            sx = i, sy = i;
            
            visit(i, i, 0);
            const int x = k % tmp.size();
            vector<int> nxt = traverse(tmp, x);
            
            int idx = 0;
            for (auto& [x, y] : points) {
                // cout << "(" << x << "," << y << ") ";
                grid[x][y] = nxt[idx++];
            }
            // cout << endl;
        }
        // cout << endl << endl;
        return grid;
    }
private:
    int n, m, sx, sy;
    bool visited[51][51];
    vector<int> tmp;
    vector<pair<int, int>> points;
    vector<vector<int>> arr;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void visit(int i, int j, int dir) {
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};
        
        tmp.push_back(arr[i][j]);
        points.emplace_back(i, j);
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[(dir + k) % 4], ny = j + dy[(dir + k) % 4];
            if (nx == sx && ny == sy) return;
            if (point_valid(nx, ny) && !visited[nx][ny]) {
                visit(nx, ny, (dir + k) % 4);
                break;
            }
        }
    }
    
    vector<int> traverse(const vector<int>& tmp, int x) {
        deque<int> q(tmp.begin(), tmp.end());
        for (int i = 0; i < x; i++) {
            const int r = q.back();
            q.pop_back();
            q.push_front(r);
        }
        vector<int> ans(q.begin(), q.end());
        return ans;
    }
};