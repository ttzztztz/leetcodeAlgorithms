class Solution {
public:
    /**
     * @param nums: the given array
     * @param limit: the limit on the absolute difference of the subarray
     * @return: Find the number of triplet subarray with the absolute difference less than or equal to limit
     */
    int tripletSubarray(vector<int> &nums, int limit) {
        // write your code here
        const int n = nums.size();
        long long ans = 0;
        const int mod = 99997867;
        
        for (int l = 0, r = 0; r < n; r++) {
            while (nums[r] - nums[l] > limit) l++;
            const int len = r - l;
            if (len >= 2) ans = (ans + len * (len - 1) / 2) % mod;
        }
        
        return ans;
    }
};
