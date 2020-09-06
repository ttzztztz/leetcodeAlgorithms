class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        typedef tuple<int, int, int> TII;
        typedef pair<int, int> PII;

        priority_queue<TII, vector<TII>, greater<>> heap;
        const int N = forest.size(), M = forest[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (forest[i][j] >= 2) heap.emplace(forest[i][j], i, j);
            }
        }
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && i < N && j >= 0 && j < M;
        };
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        int answer = 0;
        deque<PII> q = {{0, 0}};
        while (!heap.empty()) {
            int height, tx, ty;
            tie(height, tx, ty) = heap.top();
            heap.pop();
            
            int cur = 0;
            bool reached = false;
            vector<vector<bool>> visited(N, vector<bool>(M, false));
            
            while (!q.empty()) {
                const int cnt = q.size();
                for (int _ = 0; _ < cnt; _++) {
                    int i, j;
                    tie(i, j) = q.front();
                    q.pop_front();
                    
                    if (i == tx && j == ty) {
                        reached = true;
                        q.clear();
                        cur--;
                        break;
                    }
                    visited[i][j] = true;
                    
                    for (int k = 0; k < 4; k++) {
                        const int nx = i + dx[k], ny = j + dy[k];
                        
                        if (pointValid(nx, ny) && !visited[nx][ny] && forest[nx][ny] != 0) {
                            q.emplace_back(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }
                cur++;
            }
            
            if (!reached) return -1;
            answer += cur;
            q = {{tx, ty}};
        }
        return answer;
    }
};