class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        
        unordered_map<int, int> a;
        int cur = 0;
        
        for (int l = 0, r = 0; r < n; r++) {
            cur += nums[r];
            a[nums[r]]++;
            
            while (a[nums[r]] >= 2) {
                a[nums[l]]--;
                cur -= nums[l];
                if (a[l] == 0) a.erase(l);
                l++;
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};
