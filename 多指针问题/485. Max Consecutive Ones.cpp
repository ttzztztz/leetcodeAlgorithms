class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 1) continue;
            int cur = 1;
            while (i + 1 < n && nums[i + 1] == 1) {
                i++;
                cur++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};