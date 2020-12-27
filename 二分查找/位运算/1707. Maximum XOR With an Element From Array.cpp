class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(), q = queries.size();
        vector<int> ans(q, -1);
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < q; i++) {
            const int x = queries[i][0], m = queries[i][1];
            if (m < nums[0]) continue;
            
            int end = upper_bound(nums.begin(), nums.end(), m) - nums.begin();
            int start = 0;
            
            int k = 0, cur = 0;
            for (int bit = 31; bit >= 0; bit--) {
                if (x & (1 << bit)) { // hope A[i] this bit == 0
                    if (!(nums[start] & (1 << bit))) {
                        k |= 1 << bit;
                        end = lower_bound(nums.begin() + start, nums.begin() + end, cur | (1 << bit)) - nums.begin();
                    } else {
                        cur |= 1 << bit;
                    }
                } else { // hope: A[i] this bit == 1
                    if (start <= end - 1 && (nums[end - 1] & (1 << bit))) {
                        k |= 1 << bit;
                        cur |= 1 << bit;
                        start = lower_bound(nums.begin() + start, nums.begin() + end, cur) - nums.begin();
                    }
                }
            }
            ans[i] = k;
        }
        return ans;
    }
};
