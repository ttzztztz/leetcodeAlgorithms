class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int n = arr.size();
        init(n);
        bool state[100005];
        memset(state, 0, sizeof state);
        
        vector<int> ttl;
        multiset<int> cur;
        for (int i = 0; i < arr.size(); i++) {
            const int t = arr[i] - 1;
            
            state[t] = true;
            if (t - 1 >= 0 && state[t - 1] == true) {
                cur.erase(cur.lower_bound(size[findParent(t - 1)]));
                merge(t - 1, t);
            }
            if (t + 1 < n && state[t + 1] == true) {
                cur.erase(cur.lower_bound(size[findParent(t + 1)]));
                merge(t + 1, t);
            }
            
            cur.insert(size[findParent(t)]);
            if (cur.count(m)) ttl.push_back(i + 1);
        }
        
        if (ttl.empty()) return -1;
        else return ttl.back();
    }
private:
    int parent[100005], size[100005];
    void init(int n) {
        for (int i = 0; i <= n; i++) parent[i] = i, size[i] = 1;
    }
    int findParent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = findParent(u), pv = findParent(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
