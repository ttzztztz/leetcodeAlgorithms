class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        const int m = adjacentPairs.size();
        
        const int inf = numeric_limits<int>::min();
        const int n = m + 1;
        vector<int> ans(n, inf);
        
        unordered_map<int, vector<int>> appear;
        for (auto& v : adjacentPairs) {
            appear[v[0]].push_back(v[1]);
            appear[v[1]].push_back(v[0]);
        }
        
        unordered_set<int> used;
        for (auto& [k, v] : appear) {
            if (v.size() == 1) {
                if (ans.front() == inf) ans.front() = k;
                else ans.back() = k;
                
                used.insert(k);
            }
        }
        
        for (int i = 1; i < n - 1; i++) {
            const int prev = ans[i - 1];
            for (int v : appear[prev]) {
                if (used.count(v)) continue;
                used.insert(v);
                ans[i] = v;
            }
        }
        
        return ans;
    }
};
