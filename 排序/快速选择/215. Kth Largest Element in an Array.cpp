class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        target = n - k;
        return sel(nums, 0, n - 1);
    }
private:
    int target;
    int sel(vector<int>& nums, int i, int j) {
        if (i >= j) return nums[i];
        const int key = nums[i];
        const int a = i, b = j;
        
        while (i < j) {
            while (i < j && nums[j] >= key) j--;
            if (i < j) swap(nums[i], nums[j]);
            while (i < j && nums[i] < key) i++;
            if (i < j) swap(nums[i], nums[j]);
        }
        
        nums[i] = key;
        if (i < target) return sel(nums, i + 1, b);
        else if (i > target) return sel(nums, a, i - 1);
        else return nums[i];
    }
};