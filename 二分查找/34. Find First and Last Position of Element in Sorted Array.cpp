class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return { -1, -1 };
        const int n = nums.size();
        
        const int l = lower_bound(nums, target);
        const int r = upper_bound(nums, target);

        if (l >= n || nums[l] != target) return { -1, -1 };
        return { l, r - 1 };
    }
private:
    int lower_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;

            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }

    int upper_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;

            if (nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};