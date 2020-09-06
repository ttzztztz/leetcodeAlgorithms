class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        this->n = n;
        this->K = k;
        edge = vector<vector<int>>(n + 1, vector<int>{});
        for (const auto& p : dependencies) {
            edge[p[0]].push_back(p[1]);
        }
        memset(f, 0xff, sizeof f);
        
        return dfs(0);
    }
private:
    int n, K;
    vector<vector<int>> edge;
    int f[33000];
    int dfs(int state) {
        if (state == (1 << n) - 1) return 0;
        int& val = f[state];
        if (val != -1) return val;
        
        vector<int> ind(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            if (state & (1 << (u - 1))) continue;
            for (int v : edge[u]) {
                ind[v - 1]++;
            }
        }
        
        vector<int> ok;
        for (int c = 0; c < n; c++) {
            if (!(state & (1 << c)) && ind[c] == 0) {
                ok.push_back(c);
            }
        }
        
        int answer = sel(ok, K, state);
        return val = answer;
    }
    int sel(vector<int>& ok, int k, int state) {
        int answer = 9999999;
        dfs2(ok, answer, 0, k, state);
        return answer;
    }
    void dfs2(const vector<int>& ok, int& answer, int index, int k, int state) {
        if (k == 0) {
            answer = min(answer, 1 + dfs(state));
            return;
        }
        if (index == ok.size()) {
            if (k < K) answer = min(answer, 1 + dfs(state));
            return;
        }
        dfs2(ok, answer, index + 1, k, state);
        dfs2(ok, answer, index + 1, k - 1, state | (1 << ok[index]));
    }
};