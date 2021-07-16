class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = j + 1; j < n; j++) {
                while (k < n && nums[i] + nums[j] > nums[k]) k++;
                ans += max(0, k - j - 1);
            }
        }
        
        return ans;
    }
};