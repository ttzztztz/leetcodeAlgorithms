class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        // k <= n => max{ max(a[0]..a[k-2]), a[k] }
        // k > n => max_element
        
        const int n = nums.size();
        const int mx = *max_element(nums.begin(), nums.end());
        
        if (n == 1 && k % 2 == 1) return -1;
        if (k <= n) {
            int t1 = -1, t2 = -1;
            if (k < n) t2 = nums[k];
            for (int j = 0; j <= k - 2; j++) t1 = max(t1, nums[j]);
            
            return max(t1, t2);
        } else if (k > n) {
            return mx;
        }
        
        return -1;
    }
};
