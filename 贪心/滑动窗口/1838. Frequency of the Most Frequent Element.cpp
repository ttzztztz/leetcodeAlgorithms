class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        const int n = nums.size();
        typedef long long ll;
        ll sum = 0;
        for (int l = 0, r = 0; r < n; r++) {
            const ll t = nums[r];
            sum += nums[r];
            while (l < r && t * (r - l + 1) > sum + k) {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};