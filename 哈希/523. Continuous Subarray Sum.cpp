class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> cnt;
        int cur = 0, slow_cur = 0;

        for (int i = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % k;
            if (cnt.count(cur)) return true;

            if (i >= 1) {
                slow_cur = (slow_cur + nums[i - 1]) % k;
                cnt.insert(slow_cur);
            } else {
                cnt.insert(0);
            }
        }
        return false;
    }
};