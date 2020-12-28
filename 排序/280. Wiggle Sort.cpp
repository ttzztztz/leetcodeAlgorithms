class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        multiset<int> all_nums(nums.begin(), nums.end());
        int i = 0, ptr = 0;
        while (!all_nums.empty()) {
            if (i == 0) {
                nums[ptr] = *all_nums.begin();
                all_nums.erase(all_nums.begin());
            } else {
                nums[ptr] = *all_nums.rbegin();
                all_nums.erase(--all_nums.end());
            }
            
            i ^= 1;
            ptr++;
        }
    }
};
