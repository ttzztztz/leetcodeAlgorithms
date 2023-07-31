class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();

        unordered_map<int, int> appear;
        for (int i : nums) {
            appear[i]++;

            if (appear.count(i - 1)) {
                ans = max(ans, appear[i] + appear[i - 1]);
            }

            if (appear.count(i + 1)) {
                ans = max(ans, appear[i] + appear[i + 1]);
            }
        }
        return ans;
    }
};
