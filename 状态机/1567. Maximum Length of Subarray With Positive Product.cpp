class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0, negative_cnt = 0, first_negative = -1, left = 0;
        for (int i = 0; i < n; i++) {
            const int t = nums[i];
            
            if (t == 0) {
                negative_cnt = 0, first_negative = -1, left = i + 1;
            } else if (t < 0) {
                negative_cnt++;
                if (first_negative == -1) first_negative = i;
            }
            
            if (negative_cnt % 2 == 0) ans = max(ans, i - left + 1);
            else if (negative_cnt % 2 == 1) ans = max(ans, i - first_negative);
        }
        return ans;
    }
};