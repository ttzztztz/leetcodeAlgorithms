class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        const int m = nums.size();
        for (int i = 1; i < m; i++) {
            if ((nums[i] - nums[0]) % 2 != 0 || nums[i] == nums[0]) continue;
            
            const int k = (nums[i] - nums[0]) / 2;
            vector<int> ans;
            bool ok = true;
            
            unordered_map<int, int> appear;
            for (int i : nums) appear[i]++;
            
            for (int i = 0; i < m; i++) {
                const int t = nums[i];
                if (appear[t] == 0) continue;
                
                if (appear[t + 2 * k] == 0) {
                    ok = false;
                    break;
                }
                
                appear[t]--, appear[t + 2 * k]--;
                ans.push_back(t + k);
            }
            if (ok) return ans;
        }
        return {};
    }
};
