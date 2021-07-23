class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int n = nums.size();
        
        vector<int> l(n), r(n);
        l[0] = nums[0];
        for (int i = 1; i < n; i++) l[i] = max(l[i - 1], nums[i]);
        
        r[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) r[i] = min(r[i + 1], nums[i]);
        
        for (int i = 0; i + 1 < n; i++) {
            if (l[i] <= r[i + 1]) return i + 1;
        }
        return 0; // never reach this branch
    }
};