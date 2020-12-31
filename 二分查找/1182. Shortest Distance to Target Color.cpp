class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> pos[3];
        for (int i = 0; i < colors.size(); i++) {
            const int color = colors[i];
            pos[color - 1].push_back(i);
        }
        
        const int q = queries.size();
        vector<int> ans(q, -1);
        for (int i = 0; i < q; i++) {
            const int idx = queries[i][0], color = queries[i][1] - 1;
            if (pos[color].empty()) continue;
            
            auto it = lower_bound(pos[color].begin(), pos[color].end(), idx);
            if (it != pos[color].end()) {
                ans[i] = abs(*it - idx);
            }
            
            if (it != pos[color].begin()) {
                it--;
                
                if (ans[i] == -1) ans[i] = abs(*it - idx);
                else ans[i] = min(ans[i], abs(*it - idx));
            }
        }
        return ans;
    }
};
