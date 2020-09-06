class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        this->N = N;
        answer = vector<int>(N, 0);
        edges = vector<vector<int>>(N, vector<int>{});
        for (auto& v : paths) {
            v[0]--, v[1]--;
            edges[v[0]].push_back(v[1]);
            edges[v[1]].push_back(v[0]);
        }
        
        for (int i = 0; i < N; i++) {
            if (answer[i] == 0) dfs(i);
        }
        return answer;
    }
private:
    int N;
    vector<int> answer;
    vector<vector<int>> edges;
    
    void dfs(int u) {
        if (answer[u] != 0) return;
        
        for (int i = 1; i <= 4; i++) {
            bool ok = true;
            for (int v: edges[u]) {
                if (answer[v] == i) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) {
                answer[u] = i;
                for (int v : edges[u]) {
                    dfs(v);
                }
                break;
            }
        }
    }
};