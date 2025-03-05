class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> edges;
        unordered_map<char, int> indegree;

        for (int i = 0; i < words.size(); i++) {
            for (char j : words[i]) {
                if (!edges.count(j)) edges[j] = unordered_set<char>{};
            }

            if (i - 1 >= 0) {
                int ptr = 0;
                while (
                    ptr < words[i].size()
                    && ptr < words[i - 1].size()
                    && words[i][ptr] == words[i - 1][ptr]
                ) {
                    ptr++;
                }

                if (ptr < words[i].size() && ptr < words[i - 1].size()) {
                    edges[words[i - 1][ptr]].insert(words[i][ptr]);
                }

                if (ptr == words[i].size() && words[i - 1].size() > words[i].size()) return "";
            }
        }

        for (auto& [u, edge] : edges) {
            if (!indegree.count(u)) indegree[u] = 0;
            for (auto& v : edge) {
                if (!indegree.count(v)) indegree[v] = 0;
                indegree[v]++;
            }
        }

        deque<char> q = {};
        string ans;
        for (auto& [u, ind] : indegree) {
            if (ind == 0) {
                q.push_back(u);
            }
        }

        while (!q.empty()) {
            const char u = q.front();
            ans.push_back(u);
            q.pop_front();

            for (int v : edges[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push_back(v);
                }
            }
        }

        if (ans.size() < indegree.size()) return "";
        return ans;
    }
};