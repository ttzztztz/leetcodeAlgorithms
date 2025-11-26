class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();

        int ans = 0;
        int last1 = 0, last2 = 0;
        for (int i : nums) {
            const int cur = max(i, i + last2);

            ans = max(ans, cur);

            last2 = last1;
            last1 = max(last1, cur);
        }

        return ans;
    }
};