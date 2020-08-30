class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> v = {{}};
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                v.push_back(vector<int>{});
            } else {
                v[v.size() - 1].push_back(nums[i]);
            }
        }
        
        int ans = 0;
        for (const auto& s : v) {
            const int m = s.size();
            int cur = 1;
            int firstNeg = 9999999;
            for (int i = 0; i < m; i++) {
                const int num = s[i];

                if (num > 0) cur *= 1;
                else if (num < 0) firstNeg = min(firstNeg, i), cur *= -1;

                if (cur < 0 && firstNeg != 9999999) ans = max(ans, i - firstNeg);
                else if (cur > 0) ans = max(ans, i + 1);
            }
        }
        
        return ans;
    }
};