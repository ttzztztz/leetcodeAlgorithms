class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        int l = 0, r = n - 1;
        while (l + 1 < n && nums[l] <= nums[l + 1]) l++;
        while (r - 1 >= 0 && nums[r - 1] <= nums[r]) r--;
        
        if (l > r) return 0;
        
        int mi = nums[l], ma = nums[r];
        for (int k = l; k <= r; k++) {
            mi = min(mi, nums[k]);
            ma = max(ma, nums[k]);
        }
        
        while (l >= 0 && mi < nums[l]) l--;
        while (r < n && ma > nums[r]) r++;
        
        return r - l - 1;
    }
};
