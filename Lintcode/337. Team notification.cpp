class Solution {
public:
    /**
     * @param n: the number of members in team.
     * @param groups: the groups.
     * @return: return how many members will get notifications.
     */
    int teamNotification(int n, vector<vector<int>> &groups) {
        init(n);
        for (auto& group : groups) {
            for (int i = 1; i < group.size(); i++) {
                merge(group[i - 1], group[i]);
            }
        }
        
        return sze[fp(0)];
    }
private:
    int parent[100005], sze[100005];
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sze[i] = 1;
        }
    }
    int fp(int u) {
        if (parent[u] != u) return parent[u] = fp(parent[u]);
        else return u;
    }
    void merge(int u, int v) {
        const int pu = fp(u), pv = fp(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            sze[pv] += sze[pu];
        }
    }
};
