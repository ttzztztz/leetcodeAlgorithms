class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& ac : accounts) {
            const int s = accumulate(ac.begin(), ac.end(), 0);
            ans = max(ans, s);
        }
        return ans;
    }
};
