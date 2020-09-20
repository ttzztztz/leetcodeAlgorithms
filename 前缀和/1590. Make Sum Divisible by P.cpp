class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        typedef long long ll;
        vector<ll> pref = {0};
        const int n = nums.size();
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            pref.push_back(1ll * nums[i] + pref[i]);
            sum += nums[i];
        }
        
        int ans = n + 5;
        const int rest = sum % p;
        if (rest == 0) return 0;
        const int need1 = rest;
        
        unordered_map<int, int> memo = { {0, 0} };
        for (int i = 1; i <= n; i++) {
            if (memo.count((pref[i] - need1 + p) % p)) {
                ans = min(ans, i - memo[(pref[i] - need1 + p) % p]);
            }
            
            memo[pref[i] % p] = i;
        }
        
        if (ans >= n) return -1;
        else return ans;
    }
};
