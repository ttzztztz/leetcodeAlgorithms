class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        bool have_ans = false;
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                const int p = nums[i] + nums[l] + nums[r];

                if (have_ans == false || abs(target - p) < abs(target - ans)) {
                    have_ans = true;
                    ans = p;
                }
                
                if (p <= target) l++;
                else r--;
            }
        }
        return ans;
    }
};