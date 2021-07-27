class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int n = nums.size();
        int ans = 0xafafafaf;
        
        sort(nums.begin(), nums.end());
        set<int> t;
        for (int i = 0; i < n; i++) {
            const int a = nums[i];
            for (int j = i + 1; j < n; j++) {
                const int b = nums[j];
                
                const int f = target - (a + b);
                auto it = t.lower_bound(f);
                if (it != t.end()) {
                    if (ans == 0xafafafaf || abs(target - ans) > abs(target - (a + b + *it))) {
                        ans = a + b + *it;
                    }
                }
                
                if (it != t.begin()) {
                    it--;
                    if (ans == 0xafafafaf || abs(target - ans) > abs(target - (a + b + *it))) {
                        ans = a + b + *it;
                    }
                }
            }
            t.insert(a);
        }
        
        return ans;
    }
};