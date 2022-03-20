class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        for (int i = 1; i < n - 1; i++) {
            if (i >= 2 && nums[i - 1] == nums[i]) continue;
            bool is_hill = true, is_valley = false;
            bool f1 = false, f2 = false, f3 = false, f4 = false;
            
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] == nums[i]) continue;
                else if (nums[j] < nums[i]) f1 = true;
                break;
            }
            
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) continue;
                else if (nums[i] > nums[j]) f2 = true;
                break;
            }
            
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] == nums[i]) continue;
                else if (nums[j] > nums[i]) f3 = true;
                break;
            }
            
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) continue;
                else if (nums[i] < nums[j]) f4 = true;
                break;
            }
            
            is_hill = f1 && f2;
            is_valley = f3 && f4;
            ans += is_hill + is_valley;
        }
        return ans;
    }
};
