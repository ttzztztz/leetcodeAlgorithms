class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target_mod = 0;
        for (int i = 0; i < nums.size(); i++) {
            target_mod = (target_mod + nums[i]) % p;
        }
        if (target_mod == 0) return 0;

        int ans = nums.size(), cur = 0;
        unordered_map<int, int> last;
        last[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % p;

            const int target = ((cur - target_mod) % p + p) % p;
            if (last.count(target)) {
                ans = min(ans, i - last[target]);
            }
            last[cur] = i;
        }

        if (ans == nums.size()) return -1;
        return ans;
    }
};