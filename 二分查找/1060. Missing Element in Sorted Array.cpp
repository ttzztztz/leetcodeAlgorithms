class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            if (f(nums, mid) < k) l = mid + 1;
            else r = mid - 1;
        }
        
        return nums[0] + k + r;
    }
private:
    int f(const vector<int>& nums, int idx) {
        return nums[idx] - nums[0] - idx;
    }
};
