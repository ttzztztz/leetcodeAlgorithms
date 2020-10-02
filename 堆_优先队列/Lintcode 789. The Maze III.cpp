class Solution {
public:
    /**
     * @param maze: the maze
     * @param ball: the ball position
     * @param hole: the hole position
     * @return: the lexicographically smallest way
     */
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole) {
        // write your code here
        const int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        typedef tuple<int, string, int, int> State;
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m && maze[i][j] != 1;
        };
        auto nxt = [&](int i, int j, string cur, int k, int dist) -> State {
            const char more[] = { 'd', 'l', 'r', 'u' };
            const int dx[] = { 1, 0, 0, -1 };
            const int dy[] = { 0, -1, 1, 0 };
            
            cur += more[k];
            while (pointValid(i + dx[k], j + dy[k])) {
                i += dx[k], j += dy[k];
                dist++;
                if (i == hole[0] && j == hole[1]) return make_tuple(dist, cur, i, j);
            }
            return make_tuple(dist, cur, i, j);
        };
        
        State start = make_tuple(0, "", ball[0], ball[1]);
        priority_queue<State, vector<State>, greater<>> q;
        q.emplace(start);
        
        while (!q.empty()) {
            int i, j, dist;
            string cur;
            tie(dist, cur, i, j) = q.top();
            
            if (i == hole[0] && j == hole[1]) return cur;
            
            q.pop();
            if (visited[i][j]) continue;
            visited[i][j] = true;
            
            for (int k = 0; k < 4; k++) {
                int nx, ny, ndist;
                string nc;
                
                tie(ndist, nc, nx, ny) = nxt(i, j, cur, k, dist);
                if (visited[nx][ny]) continue;
                q.emplace(ndist, nc, nx, ny);
            }
        }
        
        return "impossible";
    }
};
