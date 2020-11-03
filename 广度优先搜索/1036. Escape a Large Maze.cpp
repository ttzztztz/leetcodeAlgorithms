class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        prepare(blocked, source, target);

        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
        typedef pair<int, int> State;
        
        deque<State> q = { {source[0], source[1]} };
        visited[source[0]][source[1]] = true;
        State finalState = { target[0], target[1] };
        
        for (auto& v : blocked) {
            visited[v[0]][v[1]] = true;
        }
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto state = q.front();
            auto [x, y] = state;
            q.pop_front();
            visited[x][y] = true;
            
            if (state == finalState) return true;
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (make_pair(nx, ny) == finalState) return true;
                if (!pointValid(nx, ny) || visited[nx][ny]) continue;
                
                q.emplace_back(nx, ny);
                visited[nx][ny] = true;
            }
        }
        
        return false;
    }
private:
    int n = 0, m = 0;
    void prepare(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        constexpr auto valid = [&](int i) -> bool {
            const int fin = 1e6;
            return i >= 0 && i < fin;
        };

        vector<int> allx, ally;
        for (auto& v : blocked) {
            for (int k = -1; k <= 1; k++) {
                if (valid(v[0] + k)) allx.push_back(v[0] + k);
                if (valid(v[1] + k)) ally.push_back(v[1] + k);
            }
        }
        
        for (int k = -1; k <= 1; k++) {
            if (valid(source[0] + k)) allx.push_back(source[0] + k);
            if (valid(source[1] + k)) ally.push_back(source[1] + k);
            
            if (valid(target[0] + k)) allx.push_back(target[0] + k);
            if (valid(target[1] + k)) ally.push_back(target[1] + k);
        }
        
        sort(allx.begin(), allx.end());
        sort(ally.begin(), ally.end());
        auto endx = unique(allx.begin(), allx.end());
        auto endy = unique(ally.begin(), ally.end());
        
        source[0] = lower_bound(allx.begin(), endx, source[0]) - allx.begin();
        source[1] = lower_bound(ally.begin(), endy, source[1]) - ally.begin();
        target[0] = lower_bound(allx.begin(), endx, target[0]) - allx.begin();
        target[1] = lower_bound(ally.begin(), endy, target[1]) - ally.begin();
        
        for (auto& v : blocked) {
            v[0] = lower_bound(allx.begin(), endx, v[0]) - allx.begin();
            v[1] = lower_bound(ally.begin(), endy, v[1]) - ally.begin();
        }
        
        n = endx - allx.begin(), m = endy - ally.begin();
    }
};
