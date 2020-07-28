class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int N = nums.size();
        int count = 0;
        
        for (int ptr1 = 0, ptr2 = 0; ptr1 < N; ptr1++) {
            if (nums[ptr1] == val) {
                count++;
            } else {
                nums[ptr2] = nums[ptr1];
                ptr2++;
            }
        }
        
        return N - count;
    }
};