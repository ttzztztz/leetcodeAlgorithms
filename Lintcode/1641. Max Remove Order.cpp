class Solution {
public:
    /**
     * @param mp: the board
     * @return: the max number of points we can remove
     */
    int N, M;
    int getAns(vector<vector<int>> &mp) {
        N = mp.size(), M = mp[0].size();
        
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mp[i][j] == 0) continue;
                
                for (int a = 0; a < N; a++) {
                    if (mp[a][j] == 1) merge(ID(a, j), ID(i, j));
                }
                
                for (int b = 0; b < M; b++) {
                    if (mp[i][b] == 1) merge(ID(i, b), ID(i, j));
                }
            }
        }
        
        unordered_set<int> all;
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mp[i][j] == 0) continue;
                
                const int p = findParent(ID(i, j));
                if (!all.count(p)) {
                    all.insert(p);
                    answer += size[p] - 1;
                }
            }
        }
        
        return answer;
    }
private:
    int parent[3000];
    int size[3000];
    int ID(int i, int j) {
        return i * M + j;
    }
    int findParent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void init() {
        for (int i = 0; i <= 2600; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
            size[pV] += size[pU];
        }
    }
};
