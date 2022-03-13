class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        const int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (nums[j] == key) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans.push_back(i);
        }
        
        return ans;
    }
};
