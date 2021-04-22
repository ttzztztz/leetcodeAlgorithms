class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        const int n = wall.size();
        
        int ans = n, x = 0;
        unordered_map<int, int> appear;
        for (auto& line : wall) {
            int cur = 0;
            appear[cur]++;
            for (auto& w : line) {
                cur += w;
                appear[cur]++;
            }
            x = cur;
        }
        
        for (auto& [k, v] : appear) {
            if (k == 0 || k == x) continue;
            ans = min(ans, n - v);
        }
        return ans;
    }
};