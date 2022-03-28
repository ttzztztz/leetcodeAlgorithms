class Solution {
public:
    int minDeletion(vector<int>& nums) {
        const int len = nums.size();
        vector<int> stk;
        for (int i = 0; i < len; i++) {
            const int t = nums[i];
            
            if (
                stk.empty()
                || (!stk.empty() && stk.size() % 2 == 0)
                || (!stk.empty() && stk.size() % 2 == 1 && stk.back() != t)
            ) {
                stk.push_back(t);
            }
        }
        
        if (stk.size() % 2 == 1) stk.pop_back();
        return len - stk.size();
    }
};
