class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        const int q = queries.size(), e = edgeList.size();
        init(n + 1);
        typedef tuple<int, int, int, int> State;
        vector<State> qq;
        
        sort(edgeList.begin(), edgeList.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[2] < $2[2];
        });
        for (int i = 0; i < q; i++) qq.emplace_back(queries[i][0], queries[i][1], queries[i][2], i);
        sort(qq.begin(), qq.end(), [](const auto& $1, const auto& $2) -> bool {
            return get<2>($1) < get<2>($2);
        });
        
        vector<bool> ans(q);
        for (int i = 0, j = 0; i < q; i++) {
            auto [u, v, l, idx] = qq[i];
            while (j < e && edgeList[j][2] < l) {
                merge(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            
            ans[idx] = (fp(u) == fp(v));
        }
        return ans;
    }
private:
    vector<int> parent;
    void init(int n) {
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int fp(int u) {
        if (parent[u] != u) return parent[u] = fp(parent[u]);
        else return u;
    }
    void merge(int u, int v) {
        const int pu = fp(u), pv = fp(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};
