class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            if (i - k - 1 >= 0) cnt[nums[i - k - 1]]--;

            if (cnt[nums[i]] >= 2) return true;
        }
        return false;
    }
};