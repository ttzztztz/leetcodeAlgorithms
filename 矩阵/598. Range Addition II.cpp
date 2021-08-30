class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int ans = n * m;
        for (auto& op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
            ans = n * m;
        }
        return ans;
    }
};
