class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        typedef long long ll;
        
        const int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == x) return n;
        
        vector<ll> pref = {0};
        for (int i : nums) pref.push_back(pref.back() + i);
        int ans = n + 5;
        
        unordered_map<ll, int> memo;
        memo[0] = 0;
        for (int i = 1; i <= n; i++) {
            ll fd = pref[i] - sum + x;
            if (memo.count(fd)) {
                ans = min(ans, n - (i - memo[fd]));
            }
            
            if (!memo.count(pref[i])) memo[pref[i]] = i;
        }
        
        if (ans == n + 5) return -1;
        else return ans;
    }
};
