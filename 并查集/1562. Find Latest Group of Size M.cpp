class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int n = arr.size();
        init(n);
        
        string str(n, '0');
        int ans = -1;
        unordered_map<int, int> cnts;
        
        for (int i = 1; i <= n; i++) {
            const int t = arr[i - 1] - 1;
            
            str[t] = '1';
            if (t - 1 >= 0 && str[t - 1] == '1') {
                cnts[size[find_parent(t - 1)]]--;
                merge(t - 1, t);
            }
            if (t + 1 < n && str[t + 1] == '1') {
                cnts[size[find_parent(t + 1)]]--;
                merge(t, t + 1);
            }
            
            cnts[size[find_parent(t)]]++;
            if (cnts[m] > 0) ans = i;
        }
        return ans;
    }
private:
    int parent[100005], size[100005];
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_parent(int u) {
        if (u == parent[u]) return u; 
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};