class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        init(100000);
        for (auto& p : allowedSwaps) {
            merge(p[0], p[1]);
        }
        
        const int n = source.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) continue;
            all_elem[find_parent(i)].insert(source[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) continue;
            const int pu = find_parent(i);
            if (all_elem[pu].count(target[i])) {
                all_elem[pu].erase(all_elem[pu].find(target[i]));
            } else {
                ans++;
            }
        }
        return ans;
    }
private:
    int parent[100005];
    unordered_multiset<int> all_elem[100005];
    
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};
