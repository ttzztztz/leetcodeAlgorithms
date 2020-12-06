class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> f((1 << n) + 5, -1), g((1 << n) + 5, -1);

        const int mask = (1 << n) - 1;
        const int per = n / k;

        for (int i = 0; i < (1 << n); i++) {
            const int cnt = bit_cnt(i);
            if (cnt != per) continue;
            
            set<int> all;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (all.count(nums[j])) {
                        ok = false;
                        break;
                    }
                    
                    all.insert(nums[j]);
                }
            }
            
            if (ok) {
                g[i] = *all.rbegin() - *all.begin();
            }
        }
        
        f[0] = 0;
        for (int i = 0; i < (1 << n); i++) {
            const int cnt = bit_cnt(i);
            if (cnt % per != 0) continue;

            for (int t = i; t; t = (t - 1) & i) {
                if (g[t] == -1 || f[i - t] == -1) continue;

                if (f[i] == -1) f[i] = f[i - t] + g[t];
                else f[i] = min(f[i], f[i - t] + g[t]);
            }
        }
        return f[mask];
    }
private:
    int bit_cnt(int state) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (state & (1 << i)) ans++;
        }
        return ans;
    }
};
