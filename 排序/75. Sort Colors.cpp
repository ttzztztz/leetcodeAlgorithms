class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();
        int ptr0 = 0, ptr2 = N - 1, cur = 0;
        
        while (cur <= ptr2) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[ptr0]);
                cur++, ptr0++;
            } else if (nums[cur] == 1) {
                cur++;
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[ptr2]);
                ptr2--;
            }
        }
    }
};
