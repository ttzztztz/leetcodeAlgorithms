class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> ind, outd;
        unordered_map<int, vector<int>> edges;
        
        for (auto& p : pairs) {
            const int s = p[0], e = p[1];
            edges[s].push_back(e);
            
            ind[e]++, outd[s]++;
        }
        
        vector<int> route, stk;
        for (auto& [u, _] : outd) {
            if (outd[u] - ind[u] == 1) {
                stk.push_back(u);
                break;
            }
        }
        
        if (stk.empty()) {
            stk.push_back(pairs[0][0]); // totally a cycle
        }
        
        while (!stk.empty()) {
            while (!edges[stk.back()].empty()) {
                const int u = edges[stk.back()].back();
                edges[stk.back()].pop_back();
                stk.push_back(u);
            }
            route.push_back(stk.back());
            stk.pop_back();
        }
        reverse(route.begin(), route.end());
        
        vector<vector<int>> ans;
        for (int i = 0; i + 1 < route.size(); i++) {
            ans.push_back(vector<int>{ route[i], route[i + 1] });
        }
        return ans;
    }
};