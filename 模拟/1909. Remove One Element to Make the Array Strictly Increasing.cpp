class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            int last = -1;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                if (last >= nums[j]) {
                    ok = false;
                    break;
                }
                last = nums[j];
            }
            if (ok) return true;
        }
        return false;
    }
};