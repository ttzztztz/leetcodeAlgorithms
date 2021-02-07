class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = 0, ans2 = 0;
        
        int cur1 = 0, cur2 = 0;
        for (int i : nums) {
            cur1 = max(cur1 + i, i);
            cur2 = min(cur2 + i, i);
            
            ans1 = max(ans1, cur1);
            ans2 = min(ans2, cur2);
        }
        return max(abs(ans1), abs(ans2));
    }
};
