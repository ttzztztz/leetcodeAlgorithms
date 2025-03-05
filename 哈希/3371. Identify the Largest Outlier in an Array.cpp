class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> cnt;
        for (int i : nums) cnt[i]++;

        int ans = numeric_limits<int>::min();
        for (int i : nums) {
            const int rest_sum = sum - i;
            if (((rest_sum % 2) + 2) % 2 == 1) continue;
            const int target_element = rest_sum / 2;
            int at_least_cnt = 1;
            if (i == target_element) at_least_cnt++;

            if (cnt.count(target_element) && cnt[target_element] >= at_least_cnt) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};