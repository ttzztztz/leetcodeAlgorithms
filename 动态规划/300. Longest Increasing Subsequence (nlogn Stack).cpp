class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stk;
        for (int i : nums) {
            if (stk.empty() || stk.back() < i) {
                stk.push_back(i);
            } else {
                auto it = lower_bound(stk.begin(), stk.end(), i);
                *it = i;
            }
        }
        return stk.size();
    }
};