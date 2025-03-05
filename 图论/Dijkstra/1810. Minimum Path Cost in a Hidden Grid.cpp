/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

 class Solution {
public:
    int findShortestPath(GridMaster &master) {
        dfs(master, 0, 0);
        if (!find_target) return -1;
        return dijkstra(0, 0);
    }
private:
    typedef pair<int, int> Point;
    unordered_map<string, int> cost;
    bool find_target = false;
    int target_x = -1, target_y = -1;

    string hash(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }

    void dfs(GridMaster &master, int i, int j) {
        if (master.isTarget()) {
            target_x = i, target_y = j, find_target = true;
            return;
        }

        const char dir_op[] = {'U', 'D', 'L', 'R'};
        const char rev_dir_op[] = {'D', 'U', 'R', 'L'};

        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            const char direction = dir_op[k];
            const char rev_direction = rev_dir_op[k];

            if (!master.canMove(direction)) continue;
            const int c = master.move(direction);
            const string next_hash = hash(nx, ny);
            if (!cost.count(next_hash)) {
                cost[next_hash] = c;
                dfs(master, nx, ny);
            }
            master.move(rev_direction);
        }
    }

    int dijkstra(int i, int j) {
        typedef tuple<int, int, int> State;

        unordered_map<string, int> min_cost;
        priority_queue<State, vector<State>, greater<>> q;
        q.emplace(0, i, j);
        min_cost[hash(i, j)] = 0;

        while (!q.empty()) {
            auto [dist, x, y] = q.top();
            q.pop();
            if (x == target_x && y == target_y) return dist;
            
            const int dx[] = {1, -1, 0, 0};
            const int dy[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; k++) {
                const int nx = x +dx[k], ny = y + dy[k];
                const string next_hash = hash(nx, ny);

                if (!cost.count(next_hash)) continue; // not-reachable
                const int cur_cost = cost[next_hash];
                if (min_cost.count(next_hash) && min_cost[next_hash] < dist + cur_cost) continue; // pruning
                min_cost[next_hash] = dist + cur_cost;
                q.emplace(min_cost[next_hash], nx, ny);
            }
        }
        return -1;
    }
};