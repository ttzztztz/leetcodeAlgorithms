bool in_ans[100005];
int visited[100005];

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ans;
        
        memset(in_ans, 0, sizeof in_ans);
        memset(visited, 0xff, sizeof visited);
        vector<vector<pair<int, int>>> edges;
        
        edges = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>{});
        for (auto& meeting : meetings) {
            edges[meeting[0]].emplace_back(meeting[1], meeting[2]);
            edges[meeting[1]].emplace_back(meeting[0], meeting[2]);
        }
        edges[0].emplace_back(firstPerson, 0);
        
        visited[0] = 0;
        typedef pair<int, int> State;
        priority_queue<State, vector<State>, greater<>> q;
        q.emplace(0, 0);
        
        while (!q.empty()) {
            auto [t, u] = q.top();
            q.pop();
            if (t != visited[u]) continue;

            if (!in_ans[u]) {
                in_ans[u] = true;
                ans.push_back(u);
            }
            
            for (auto[v, nt] : edges[u]) {
                if (nt < t) continue;
                
                if (visited[v] == -1 || visited[v] > nt) {
                    visited[v] = nt;
                    q.emplace(nt, v);
                }
            }
        }
        return ans;
    }
};
