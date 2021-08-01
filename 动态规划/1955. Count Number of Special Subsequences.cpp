class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        memset(f, 0xff, sizeof f);
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) ans = (ans + dfs(i + 1, nums[i])) % mod;
        }
        return ans;
    }
private:
    const int mod = 1e9+7;
    typedef long long ll;
    
    vector<int> nums;
    int n;
    ll f[100005][3];
    
    ll dfs(int idx, int last) {
        if (idx == n) {
            return (last == 2) ? 1 : 0;
        }
        
        ll& val = f[idx][last];
        if (val != -1) return val;
        ll ans = 0;
        ans = (ans + dfs(idx + 1, last)) % mod;
        if (nums[idx] == last || last + 1 == nums[idx]) ans = (ans + dfs(idx + 1, nums[idx])) % mod;
        return val = ans;
    }
};