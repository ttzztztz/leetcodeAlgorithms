class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            const int prev = i - 1 >= 0 ? nums[i - 1] : -2147483648;
            const int nxt = i + 1 < N ? nums[i + 1] : -2147483648;
            
            if (nums[i] >= prev && nums[i] >= nxt) return i;
        }
        return -1;
    }
};