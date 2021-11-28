class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ans(n, -1);
        if (2 * k >= n) return ans;
        
        typedef long long ll;
        ll cur = 0;
        for (int i = 0; i <= 2 * k; i++) cur += nums[i];
        
        ans[k] = cur / (2 * k + 1);
        for (int i = k + 1; i + k < n; i++) {
            cur -= nums[i - k - 1];
            cur += nums[i + k];
            ans[i] = cur / (2 * k + 1);
        }
        
        return ans;
    }
};
