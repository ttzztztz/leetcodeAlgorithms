class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> psum;
        psum[0] = -1;

        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            const int d = nums[i] == 0 ? 1 : -1;
            sum += d;

            if (psum.count(sum)) {
                ans = max(ans, i - psum[sum]);
            } else {
                psum[sum] = i;
            }
        }
        return ans;
    }
};