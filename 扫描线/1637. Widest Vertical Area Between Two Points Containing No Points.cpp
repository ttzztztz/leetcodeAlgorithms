class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> f;
        for (auto& p : points) f.insert(p[0]);
        
        int ans = 0;
        for (auto it1 = f.begin(), it2 = ++f.begin(); it2 != f.end(); it1++, it2++) {
            ans = max(ans, *it2 - *it1);
        }
        return ans;
    }
};
