class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        const int n = nums.size();
        typedef long long ll;
        
        int ans = 0, last = -1;
        ll sum = 0;
        unordered_map<ll, int> appear;
        appear[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            const ll t = sum - target;
            if (appear.count(t) && last <= appear[t]) {
                last = i;
                ans++;
            }
            appear[sum] = i;
        }
        return ans;
    }
};