class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        const int n = nums.size();

        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0, ans = 0;
        for (int i : nums) {
            sum += i;
            if (cnt.count(sum - k)) ans += cnt[sum - k];
            cnt[sum]++;
        }
        return ans;
    }
};