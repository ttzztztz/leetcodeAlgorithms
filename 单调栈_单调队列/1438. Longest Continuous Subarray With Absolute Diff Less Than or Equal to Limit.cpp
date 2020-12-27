class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int n = nums.size();
        int ans = 0;
        
        deque<int> f, g;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (!f.empty() && nums[f.back()] <= nums[r]) f.pop_back();
            while (!g.empty() && nums[g.back()] >= nums[r]) g.pop_back();
            
            f.push_back(r), g.push_back(r);
            while (l < r && nums[f.front()] - nums[g.front()] > limit) {
                if (f.front() == l) f.pop_front();
                if (g.front() == l) g.pop_front();
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
