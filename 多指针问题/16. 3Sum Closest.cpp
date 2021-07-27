class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int n = nums.size();
        int ans = 0xafafafaf;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                const int t = nums[i] + nums[l] + nums[r];
                if (t > target) {
                    r--;
                } else if (t < target) {
                    l++;
                } else { // t == target
                    return target;
                }
                
                if (abs(t - target) < abs(ans - target)) ans = t;
            }
        }
        return ans;
    }
};