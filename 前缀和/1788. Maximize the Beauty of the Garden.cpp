class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        const int n = flowers.size();
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + max(flowers[i - 1], 0);
        }
        
        auto sum = [&](int i, int j) -> int {
            return pref[j + 1] - pref[i];
        };

        int ans = numeric_limits<int>::min();
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            if (idx.count(flowers[i])) {
                ans = max(ans, sum(idx[flowers[i]] + 1, i - 1) + 2 * flowers[i]);
            } else {
                idx[flowers[i]] = i;
            }
        }
        return ans;
    }
};
