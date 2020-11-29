class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        const int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] > nums[i] && stk.size() - 1 + (n - i) >= k) stk.pop_back();
            stk.push_back(i);
        }
        
        if (stk.size() > k) stk.resize(k);
        vector<int> ans;
        for (int i : stk) ans.push_back(nums[i]);
        return ans;
    }
};
