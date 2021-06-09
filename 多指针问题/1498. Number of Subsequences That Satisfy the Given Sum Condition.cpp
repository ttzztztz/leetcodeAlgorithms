class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        const int n = nums.size();
        ll ans = 0;
        for (int l = 0, r = n - 1; l <= r; l++) {
            while (l <= r && nums[l] + nums[r] > target) r--;
            ans = (ans + fastpow(2, r - l)) % mod;
        }
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    ll fastpow(int a, int b) {
        if (b < 0) return 0;
        ll ans = 1, base = a;
        while (b) {
            if (b % 2) ans = (ans * base) % mod;
            base = (base * base) % mod;
            
            b >>= 1;
        }
        return ans;
    }
};