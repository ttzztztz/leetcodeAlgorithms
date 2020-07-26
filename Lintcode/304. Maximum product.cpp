class Solution {
public:
    /**
     * @param nums: Unordered array
     * @return: return the largest product
     */
    long long MaximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        
        const long long ans1 = 1ll * nums[N - 1] * nums[N - 2] * nums[N - 3];
        const long long ans2 = 1ll * nums[0] * nums[1] * nums[N - 1];
        
        if (ans1 > ans2) return ans1;
        else return ans2;
    }
};