class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        
        const int ans1 = nums[N - 1] * nums[N - 2] * nums[N - 3];
        const int ans2 = nums[0] * nums[1] * nums[N - 1];
        
        return max(ans1, ans2);
    }
};
