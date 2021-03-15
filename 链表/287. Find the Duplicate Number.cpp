class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ptr1 = 0, ptr2 = 0;
        const int n = nums.size();
        do {
            ptr1 = nums[nums[ptr1]];
            ptr2 = nums[ptr2];
        } while (ptr1 != ptr2);
        
        ptr1 = 0;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};