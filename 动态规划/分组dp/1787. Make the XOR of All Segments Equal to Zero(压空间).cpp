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
        vector<int> f(1 << 10, inf);
        f[0] = 0;
        for (int i = k - 1; i >= 0; i--) {
            vector<int> g(1 << 10, cnt[i] + *min_element(f.begin(), f.end()));
            for (int j = 0; j < (1 << 10); j++) {
                for (auto& [val, cost] : appear[i]) {
                    g[j] = min(g[j], f[j ^ val] + cnt[i] - cost);
                }
            }
            f = move(g);
        }
        return f[0];
    }
};
