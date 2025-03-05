class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();

        if (nums.empty()) return 0;

        int ans = 0, ans_l = 0;
        vector<int> f(n, 0), cnt(n, 0);
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < n; j++) {
                if (nums[j] < nums[i]) {
                    if (f[i] == f[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                    
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }

            if (ans_l == f[i]) ans += cnt[i];
            if (ans_l < f[i]) {
                ans = cnt[i];
                ans_l = f[i];
            }
        }

        return ans;
    }
};