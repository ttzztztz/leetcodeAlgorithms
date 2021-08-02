class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int, int> t;
        for (int i = 0; i < n; i++) {
            const int u = nums[i];
            if (t.count(target - u)) {
                return { t[target - u], i };
            }
            t[u] = i;
        }
        return {}; // never reach this branch
    }
};
