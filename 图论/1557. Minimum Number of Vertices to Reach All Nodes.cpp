class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int> ind(n, 0);
        for (auto& v : e) {
            ind[v[1]]++;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
