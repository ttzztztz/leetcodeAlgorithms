typedef pair<int, int> Point;
typedef pair<Point, Point> State;

class Solution {
public:
    int N = 0;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < N;
    }

    bool stateValid(const State& state) {
        return pointValid(state.first.first, state.first.second) && pointValid(state.second.first, state.second.second);
    }

    int minimumMoves(vector<vector<int>>& grid) {
        N = grid.size();

        State initial = {{0, 1}, {0, 0}};
        State finalState = {{N - 1, N - 1}, {N - 1, N - 2}};
        set<State> visited;
        visited.insert(initial);

        deque<pair<State, int>> queue;
        queue.emplace_back(initial, 0);
        while (!queue.empty()) {
            State state;
            int dist;
            tie(state, dist) = queue.front();
            queue.pop_front();

            if (state == finalState) {
                return dist;
            }

            // right
            State nextState = state;
            nextState.first = {nextState.first.first + 1, nextState.first.second};
            nextState.second = {nextState.second.first + 1, nextState.second.second};
            if (stateValid(nextState) && grid[nextState.first.first][nextState.first.second] == 0 && grid[nextState.second.first][nextState.second.second] == 0) {
                if (!visited.count(nextState)) {
                    visited.insert(nextState);
                    queue.emplace_back(nextState, dist + 1);
                }
            }
            // down
            nextState = state;
            nextState.first = {nextState.first.first, nextState.first.second + 1};
            nextState.second = {nextState.second.first, nextState.second.second + 1};
            if (stateValid(nextState) && grid[nextState.first.first][nextState.first.second] == 0 && grid[nextState.second.first][nextState.second.second] == 0) {
                if (!visited.count(nextState)) {
                    visited.insert(nextState);
                    queue.emplace_back(nextState, dist + 1);
                }
            }
            // clockwise
            if (state.first.first == state.second.first && state.first.second == state.second.second + 1) {
                nextState = state;
                nextState.first = {nextState.first.first + 1, nextState.first.second - 1};
                nextState.second = {nextState.second.first, nextState.second.second};
                if (stateValid(nextState) && grid[nextState.first.first][nextState.first.second] == 0 && grid[nextState.second.first][nextState.second.second] == 0 && grid[state.second.first + 1][state.second.second + 1] == 0) {
                    if (!visited.count(nextState)) {
                        visited.insert(nextState);
                        queue.emplace_back(nextState, dist + 1);
                    }
                }
            }
            // counterclockwise
            if (state.first.first == state.second.first + 1 && state.first.second == state.second.second) {
                nextState = state;
                nextState.first = {nextState.first.first - 1, nextState.first.second + 1};
                nextState.second = {nextState.second.first, nextState.second.second};
                if (stateValid(nextState) && grid[nextState.first.first][nextState.first.second] == 0 && grid[nextState.second.first][nextState.second.second] == 0 && grid[state.second.first + 1][state.second.second + 1] == 0) {
                    if (!visited.count(nextState)) {
                        visited.insert(nextState);
                        queue.emplace_back(nextState, dist + 1);
                    }
                }
            }
        }
        return -1;
    }
};