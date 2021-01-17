class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> s;
        for (auto& r : rectangles) {
            s[min(r[0], r[1])]++;
        }
        
        int ans = numeric_limits<int>::min();
        int cnt = 0;
        for (auto& [k, v] : s) {
            if (k > ans) {
                cnt = v;
                ans = k;
            }
        }
        
        return cnt;
    }
};
