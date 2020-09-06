class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        N = board.size(), M = board[0].size();
        init();
        
        // for (const auto& p : num) cout << p.first << ": " << p.second.first << ", " << p.second.second << endl;
        
        int answer = 0;
        unordered_set<int> visited;
        deque<int> q = {1};
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                int id = q.front();
                if (id == N * M) return answer;
                q.pop_front();
                visited.insert(id);
                
                for (int k = 1; k <= 6 && id + k <= N * M; k++) {
                    const int nxt = id + k;
                    
                    if (!num.count(nxt)) {
                        continue;
                    }

                    int a, b;
                    tie(a, b) = num[nxt];
                    
                    const int fin = board[a][b] == -1 ? nxt : board[a][b];
                    if (fin == N * M) return answer + 1;

                    if (visited.count(fin)) {
                        continue;
                    }
                    visited.insert(fin);
                    q.push_back(fin);
                }
                
            }
            answer++;
        }
        return -1;
    }
private:
    typedef pair<int, int> PII;
    unordered_map<int, PII> num;
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    void init() {
        int i = N - 1, j = 0, cnt = 1, dir = 0;
        auto go_next = [&]() -> void {
            if (dir == 0) {
                j++;
            } else if (dir == 1) {
                j--;
            }
            
            if (j == M) {
                j--;
                i--;
                dir ^= 1;
            }
            
            if (j == -1) {
                j++;
                i--;
                dir ^= 1;
            }
        };
        do {
            num[cnt] = {i, j};
            go_next();
            cnt++;
        } while (cnt != N * M);
        num[cnt] = {i, j};
    }
};
