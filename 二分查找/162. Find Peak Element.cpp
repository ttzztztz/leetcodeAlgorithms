class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        const int infl = numeric_limits<int>::min();
        
        nums.insert(nums.begin(), infl);
        nums.insert(nums.end(), infl);
        
        int l = 1, r = n;
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            const int l_val = nums[mid - 1], r_val = nums[mid + 1];
            if (l_val <= nums[mid] && nums[mid] >= r_val) {
                return mid - 1;
            } else if (l_val <= nums[mid] && nums[mid] <= r_val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};