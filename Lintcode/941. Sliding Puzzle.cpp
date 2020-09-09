class Solution {
public:
    /**
     * @param board: the given board
     * @return:  the least number of moves required so that the state of the board is solved
     */
    int slidingPuzzle(vector<vector<int>> &board) {
        unordered_set<string> visited;
        deque<VVI> q = {board};
        
        VVI finalState = {{1,2,3},{4,5,0}};
        const int n = 2, m = 3;
        
        int answer = 0;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                VVI cur = q.front();
                q.pop_front();
                visited.insert(hash(cur));
                
                if (cur == finalState) return answer;
                int x0 = 0, y0 = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (cur[i][j] == 0) {
                            x0 = i, y0 = j;
                        }
                    }
                }
                

                for (int k = 0; k < 4; k++) {
                    const int nx = x0 + dx[k], ny = y0 + dy[k];
                    if (pointValid(nx, ny)) {
                        swap(cur[x0][y0], cur[nx][ny]);
                        if (!visited.count(hash(cur))) {
                            if (cur == finalState) return answer + 1;
                            visited.insert(hash(cur));
                            q.push_back(cur);
                        }
                        swap(cur[x0][y0], cur[nx][ny]);
                    }
                }
            }
            
            answer++;
        }
        
        return -1;
    }
private:
    typedef vector<vector<int>> VVI;
    string hash(const VVI& v) {
        string answer;
        for (auto& a : v) {
            for (auto& b : a) {
                answer += to_string(b) + ",";
            }
        }
        return answer;
    }
    
    bool pointValid(int i, int j) {
        return i >= 0 && i <= 1 && j >= 0 && j <= 2;
    }
};