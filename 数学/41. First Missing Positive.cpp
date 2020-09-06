class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();
        
        int i = 0;
        while (i < N) {
            const int num = nums[i];
            if (num >= 1 && num <= N && num != nums[num - 1]) {
                swap(nums[i], nums[num - 1]);
            } else {
                i++;
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        
        return N + 1;
    }
};
