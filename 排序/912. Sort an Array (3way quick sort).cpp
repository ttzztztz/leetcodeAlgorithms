class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            const int n = nums.size();
            quick_sort(nums, 0, n - 1);
            return nums;
        }
    private:
        void quick_sort(vector<int>& nums, int i, int j) {
            if (i >= j) return;
    
            int lt = i, cur = i, gt = j;
            const int pivot = nums[(i + j) / 2];
            while (cur <= gt) {
                if (nums[cur] < pivot) {
                    swap(nums[lt], nums[cur]);
                    lt++, cur++;
                } else if (nums[cur] == pivot) {
                    cur++;
                } else { // nums[cur] > pivot
                    swap(nums[cur], nums[gt]);
                    gt--;
                }
            }
    
            quick_sort(nums, i, lt - 1);
            quick_sort(nums, gt + 1, j);
        }
    };