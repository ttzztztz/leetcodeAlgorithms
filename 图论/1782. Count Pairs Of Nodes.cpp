class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        const int q = queries.size();
        init();
        vector<int> answer(q, 0), g(n + 1, 0);
        vector<vector<int>> e(n + 1);
        unordered_map<int, int> ac;
        for (auto& ed : edges) {
            if (!ac.count(h(min(ed[0], ed[1]), max(ed[0], ed[1])))) {
                e[min(ed[0], ed[1])].push_back(max(ed[0], ed[1]));
            }
            ac[h(min(ed[0], ed[1]), max(ed[0], ed[1]))]++;
            g[ed[0]]++, g[ed[1]]++;
        }
        
        for (int i = n; i >= 1; i--) {
            for (int v : e[i]) {
                inc(g[v], -1);
                inc(g[v] - ac[h(i, v)], 1);
            }
            
            for (int t = 0; t < q; t++) {
                answer[t] += query(100000) - query(queries[t] - g[i]);
            }
            
            for (int v : e[i]) {
                inc(g[v], 1);
                inc(g[v] - ac[h(i, v)], -1);
            }
            inc(g[i], 1);
        }
        return answer;
    }
private:
    int h(int a, int b) {
        return a * 100000 + b;
    }
    int f[100005];
    void init() {
        memset(f, 0, sizeof f);
    }
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int u) {
        u++;
        int ans = 0;
        while (u > 0) {
            ans += f[u];
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int v) {
        u++;
        while (u > 0 && u <= 100001) {
            f[u] += v;
            u += lowbit(u);
        }
    }
};
