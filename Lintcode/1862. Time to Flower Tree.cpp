class Solution {
public:
    /**
     * @param father: the father of every node
     * @param time: the time from father[i] to node i
     * @return: time to flower tree
     */
    int timeToFlowerTree(vector<int> &father, vector<int> &time) {
        time[0] = 0;
        const int N = father.size();
        edges = vector<vector<int>>(N + 5, vector<int>{});
        for (int i = 1; i < N; i++) {
            edges[father[i]].push_back(i);
        }
        
        return dfs(0, time, -1);
    }
private:
    vector<vector<int>> edges;
    int dfs(int u, const vector<int> &time, int parent) {
        int answer = 0;
        for (int v : edges[u]) {
            if (v == parent) continue;
            answer = max(answer, dfs(v, time, u));
        }
        return answer + time[u];
    }
};
