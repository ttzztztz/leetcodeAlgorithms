class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> cur = nums;
        sort(cur.begin(), cur.end());
        
        const int N = nums.size();
        const int mid = (N - 1) / 2;
        reverse(cur.begin(), cur.begin() + mid + 1);
        reverse(cur.begin() + mid + 1, cur.end());
        int ptr1 = 0, ptr2 = mid + 1;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 1) {
                nums[i] = cur[ptr2++];
            } else {
                nums[i] = cur[ptr1++];
            }
        }
    }
};
