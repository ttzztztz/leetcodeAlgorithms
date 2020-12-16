class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        if (s.empty()) return ans;
        
        const int n = s.size();
        for (int len = 1, r = 1; r < n; r++) {
            if (s[r] == s[r - 1]) {
                len++;
                if (len == 3) ans.push_back(vector<int>{ r - len + 1, r });
                else if (len > 3) ans.back()[1] = r;
            } else {
                len = 1;
            }
        }
        
        return ans;
    }
};
