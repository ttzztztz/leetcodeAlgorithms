class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            int last_idx = i % n;
            bool ok = true;
            for (int j = 1; j < n; j++) {
                const int idx = (i + j) % n;
                
                if (nums[last_idx] > nums[idx]) {
                    ok = false;
                    break;
                }
                
                last_idx = idx;
            }
            
            if (ok) return true;
        }
        return false;
    }
};
