class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>{});
        for (auto& prerequisite : prerequisites) {
            edges[prerequisite[0]].push_back(prerequisite[1]);
            ind[prerequisite[1]]++;
        }
        
        deque<int> q;
        int ans = 0;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) q.push_back(i);
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop_front();
            ans++;

            for (int v : edges[u]) {
                ind[v]--;
                if (ind[v] == 0) q.push_back(v);
            }
        }
        return ans == numCourses;
    }
};