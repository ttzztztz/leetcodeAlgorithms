class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<unordered_map<int, int>> appear(k);
        vector<int> cnt(k);
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[i % k]++;
            appear[i % k][nums[i]]++;
        }
        
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> f(k + 1, vector<int>(1 << 10, inf));
        f[k][0] = 0;
        for (int i = k - 1; i >= 0; i--) {
            f[i] = vector<int>(1 << 10, cnt[i] + *min_element(f[i + 1].begin(), f[i + 1].end()));
            
            for (int j = 0; j < (1 << 10); j++) {
                for (auto& [val, cost] : appear[i]) {
                    f[i][j] = min(f[i][j], f[i + 1][j ^ val] + cnt[i] - cost);
                }
            }
        }
        return f[0][0];
    }
};
