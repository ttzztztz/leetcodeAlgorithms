class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        if (n == 1) return { 0 };

        vector<vector<int>> edges(n);
        vector<int> degree(n, 0), ans;
        deque<int> q;

        for (auto& ee: e) {
            const int s = ee[0];
            const int t = ee[1];

            degree[s]++, degree[t]++;
            edges[s].push_back(t);
            edges[t].push_back(s);
        }

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push_back(i);
            }
        }

        while (!q.empty()) {
            const int cnt = q.size();
            vector<int> cur;

            for (int i = 0; i < cnt; i++) {
                const int u = q.front();
                cur.push_back(u);
                q.pop_front();

                for (int v : edges[u]) {
                    degree[v]--;
                    if (degree[v] == 1) q.push_back(v);
                }
            }
            if (q.empty()) ans = cur;
        }
        return ans;
    }
};