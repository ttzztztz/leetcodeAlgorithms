class Solution {
public:
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }

    bool isOK(const vector<vector<int>>& mat) {
        for (const vector<int>& i : mat) {
            for (const int& j : i) {
                if (j != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<int>> flip(vector<vector<int>> in, int i, int j) {
        in[i][j] = !in[i][j];
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            const int nextX = i + dx[k], nextY = j + dy[k];
            if (pointValid(nextX, nextY)) {
                in[nextX][nextY] = !in[nextX][nextY];
            }
        }

        return in;
    }
    int minFlips(vector<vector<int>>& mat) {
        N = mat.size(), M = mat[0].size();
        deque<pair<vector<vector<int>>, int>> queue;
        set<vector<vector<int>>> visited;
        queue.emplace_back(mat, 0);

        while (!queue.empty()) {
            vector<vector<int>> map = queue.front().first;
            int dist = queue.front().second;

            if (isOK(map)) {
                return dist;
            }

            queue.pop_front();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    vector<vector<int>> nextMap = flip(map, i, j);
                    if (!visited.count(nextMap)) {
                        queue.emplace_back(nextMap, dist + 1);
                        visited.insert(nextMap);
                    }
                }
            }
        }

        return -1;
    }
};