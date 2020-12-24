class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> ind(N + 1, 0);
        vector<vector<int>> edges(N + 1, vector<int>{});
        for (auto& relation : relations) {
            edges[relation[0]].push_back(relation[1]);
            ind[relation[1]]++;
        }
        
        int ans = 0;
        deque<int> q;
        for (int i = 1; i <= N; i++) {
            if (ind[i] == 0) q.push_back(i);
        }
        
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                const int u = q.front();
                q.pop_front();
                
                for (int v : edges[u]) {
                    ind[v]--;
                    if (ind[v] == 0) q.push_back(v);
                }
            }
            ans++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (ind[i] >= 1) return -1; // circle
        }
        return ans;
    }
};
