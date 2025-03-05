class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;

        const int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            const int mid = (l + r) / 2;

            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};