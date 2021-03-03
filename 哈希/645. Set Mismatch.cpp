class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> ans(2, 0);
        unordered_map<int, int> appear;
        for (int i : nums) {
            if (!appear.count(i)) {
                appear[i]++;
            } else {
                ans[0] = i;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (!appear.count(i)) {
                ans[1] = i;
            }
        }
        return ans;
    }
};
