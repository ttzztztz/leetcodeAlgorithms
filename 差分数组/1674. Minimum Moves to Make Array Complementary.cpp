class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int n = nums.size(), m = n / 2;
        vector<int> diff(limit * 2 + 2, 0);

        for (int i = 0; i < m; i++) {
            const int l = nums[i], r = nums[n - i - 1];
            const int a = min(l, r), b = max(l, r);
            
            diff[1 + a]--;
            diff[a + b]--;
            diff[a + b + 1]++;
            diff[b + limit + 1]++;
        }
        
        int ans = n, cur = n;
        for (int i = 0; i <= limit * 2; i++) {
            cur += diff[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};
