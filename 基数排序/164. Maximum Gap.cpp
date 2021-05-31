class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        
        int ans = 0;
        vector<int> buf(n);
        int exp = 1;
        const int maxn = *max_element(nums.begin(), nums.end());
        while (exp <= maxn) {
            vector<int> cnt(10, 0);
            for (int i = 0; i < n; i++) {
                const int d = (nums[i] / exp) % 10;
                cnt[d]++;
            }
            
            for (int i = 1; i < 10; i++) {
                cnt[i] += cnt[i - 1];
            }
            
            for (int i = n - 1; i >= 0; i--) {
                const int d = (nums[i] / exp) % 10;
                buf[cnt[d] - 1] = nums[i];
                cnt[d]--;
            }
            
            nums = buf;
            exp *= 10;
        }
        
        for (int i = 1; i < n; i++) ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};