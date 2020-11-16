class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        bool visited[6005][2];
        memset(visited, 0, sizeof visited);
        for (int i : forbidden) visited[i][0] = visited[i][1] = true;

        typedef tuple<int, int, bool> State; // jumps, idx, last
        deque<State> q;
        q.emplace_back(0, 0, false);
        while (!q.empty()) {
            auto [jumps, idx, last] = q.front();
            q.pop_front();
            visited[idx][last] = true;

            if (idx == x) return jumps;
            int t = idx + a;
            if (t < 6000 && !visited[t][0]) {
                visited[t][0] = true;
                q.emplace_back(jumps + 1, t, false);
            }

            // backward
            if (!last) {
                t = idx - b;
                if (t > 0 && !visited[t][1]) {
                    visited[t][1] = true;
                    q.emplace_back(jumps + 1, t, true);
                }
            }
        }
        
        return -1;
    }
};
