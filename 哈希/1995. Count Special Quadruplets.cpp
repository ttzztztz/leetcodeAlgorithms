class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
                ans += cnt[nums[k] - nums[j] - nums[i]];
            }
            cnt[nums[i]]++;
        }
        return ans;
    }
};