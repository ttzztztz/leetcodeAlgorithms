class Solution {
    public:
        vector<int> findBuildings(vector<int>& heights) {
            if (heights.empty()) return {};
    
            vector<int> ans;
            for (int i = 0; i < heights.size(); i++) {
                while (!ans.empty() && heights[ans.back()] <= heights[i]) ans.pop_back();
                ans.push_back(i);
            }
            return ans;
        }
    };