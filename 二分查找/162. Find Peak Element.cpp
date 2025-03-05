class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        const int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            const int val = nums[mid];
            const int lval = mid - 1 >= 0 ? nums[mid - 1] : numeric_limits<int>::min();
            const int rval = mid + 1 < n ? nums[mid + 1] : numeric_limits<int>::min();

            if (lval <= val && val >= rval) return mid;

            if (lval <= val && val <= rval) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};