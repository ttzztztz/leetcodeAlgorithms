class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum[nums.size() + 1];
        std::memset(sum, 0, sizeof(sum));

        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        unordered_set<int> set;

        int cache = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (set.count(0 == k ? sum[i] : sum[i] % k)) {
                return true;
            }
            set.insert(cache);
            cache = 0 == k ? sum[i] : sum[i] % k;
        }

        return false;
    }
};