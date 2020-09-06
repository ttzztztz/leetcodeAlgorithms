class Solution {
public:
    /**
     * @param N: an integer
     * @param edges: the edges
     * @return: a list ans, where ans[i] is the sum of the distances between node i and all other nodes
     */
    vector<int> answer, size;
    vector<vector<int>> graph;
    int N;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        answer = vector<int>(N, 0);
        size = vector<int>(N + 1, 1);
        graph = vector<vector<int>>(N + 1, vector<int>{});
        this->N = N;
        
        for (const vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs1(0, -1);
        dfs2(0, -1);
        return answer;
    }
    void dfs1(int u, int parent) {
        for (int v : graph[u]) {
            if (v == parent) continue;
            
            dfs1(v, u);
            size[u] += size[v];
            answer[0] += size[v];
        }
    }
    void dfs2(int u, int parent) {
        for (int v : graph[u]) {
            if (v == parent) continue;
            
            answer[v] = answer[u] + N - 2 * size[v];
            dfs2(v, u);
        }
    }
};
