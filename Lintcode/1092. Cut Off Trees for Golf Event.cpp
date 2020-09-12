class Solution {
public:
    /**
     * @param forest: a list of integers
     * @return: return a integer
     */
    int cutOffTree(vector<vector<int>> &a) {
        int answer = 0;
        const int n = a.size(), m = a[0].size();
        
        typedef pair<int, int> PII;
        typedef tuple<int, int, int> TII;
        
        priority_queue<TII, vector<TII>, greater<>> heap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= 2) heap.emplace(a[i][j], i, j);
            }
        }
        
        const int dx[] = { -1, 1, 0, 0 };
        const int dy[] = { 0, 0, -1, 1 };
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        int lx = 0, ly = 0;
        while (!heap.empty()) {
            int h, x, y;
            tie(h, x, y) = heap.top();
            heap.pop();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            deque<PII> q = { {lx, ly} };
            bool find = false;
            while (!q.empty()) {
                const int cnt = q.size();
                for (int _ = 0; _ < cnt; _++) {
                    int i, j;
                    tie(i, j) = q.front();
                    
                    if (i == x && j == y) {
                        find = true;
                        break;
                    }
                    visited[i][j] = true;
                    q.pop_front();
                    
                    for (int k = 0; k < 4; k++) {
                        const int nx = i + dx[k], ny = j + dy[k];
                        if (!pointValid(nx, ny) || a[nx][ny] == 0 || visited[nx][ny]) continue;
                        
                        visited[nx][ny] = true;
                        q.emplace_back(nx, ny);
                    }
                }
                
                if (find) break;
                answer++;
            }
            
            if (!find) return -1;
            lx = x, ly = y;
        }
        return answer;
    }
};
