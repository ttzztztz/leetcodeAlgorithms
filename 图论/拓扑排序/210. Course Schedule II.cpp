class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>{});

        for (auto& req : prerequisites) {
            edges[req[1]].push_back(req[0]);
            ind[req[0]]++;
        }

        vector<int> ans;
        deque<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) q.push_back(i);
        }
        

        while (!q.empty()) {
            const int u = q.front();
            ans.push_back(u);
            q.pop_front();

            for (int v : edges[u]) {
                ind[v]--;

                if (ind[v] == 0) q.push_back(v);
            }
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};