class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for (int i : s) {
            if (s.count(i - 1)) continue;

            int cur = 1;
            while (s.count(i + cur)) {
                cur++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};