class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        const int n = nums.size();
        init(n);
        
        for (int i = 0; i < n; i++) {
            merge(i, nums[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, size[findParent(i)]);
        }
        return ans;
    }
private:
    vector<int> parent, size;
    void init(int n) {
        size = parent = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
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
