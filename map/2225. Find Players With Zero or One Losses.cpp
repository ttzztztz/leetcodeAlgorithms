class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> loss;
        
        for (auto& m : matches) {
            const int w = m[0], l = m[1];
            
            loss[w] += 0;
            loss[l] += 1;
        }
        
        for (auto& [k, v] : loss) {
            if (v == 0) ans[0].push_back(k);
            else if (v == 1) ans[1].push_back(k);
        }
        
        return ans;
    }
};
