class Solution {
public:
    /**
     * @param matrix: The 3*3 matrix
     * @return: The answer
     */
    string jigsawPuzzle(vector<vector<int>> &matrix) {
        const vector<vector<int>> finalState = {{1,2,3},{4,5,6},{7,8,0}};
        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, 1, 0, -1};
        
        
        unordered_set<string> visited;
        visited.insert(hash(matrix));
        deque<vector<vector<int>>> queue;
        queue.emplace_back(matrix);
        if (matrix == finalState) return "YES";
        
        while (!queue.empty()) {
            vector<vector<int>> cur = queue.front();
            queue.pop_front();
            
            int zeroX = -1, zeroY = -1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (cur[i][j] == 0) {
                        zeroX = i, zeroY = j;
                        break;
                    }
                }
                if (zeroX != -1 && zeroY != -1) break;
            }
            
            for (int k = 0; k < 4; k++) {
                const int nx = zeroX + dx[k], ny = zeroY + dy[k];
                if (!pointValid(nx, ny)) continue;
                swap(cur[zeroX][zeroY], cur[nx][ny]);
                if (!visited.count(hash(cur))) {
                    visited.insert(hash(cur));
                    if (cur == finalState) return "YES";
                    queue.push_back(cur);
                }
                swap(cur[zeroX][zeroY], cur[nx][ny]);
            }
            
        }
        
        return "NO";
    }
private:
    string hash(const vector<vector<int>>& state) {
        string answer;
        for (const vector<int>& s : state) {
            for (const int n : s) {
                answer += to_string(n);
            }
        }
        return answer;
    }
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < 3 && j < 3;
    }
};
