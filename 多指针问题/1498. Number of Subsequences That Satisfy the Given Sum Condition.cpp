class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        const int n = nums.size();
        ll ans = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pow(2, r - l)) % mod;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
private:
    const int mod = 1e9+7;
    typedef long long ll;
    ll pow(ll base, int e) {
        ll ans = 1;
        while (e) {
            if (e % 2 == 1) {
                ans = (ans * base) % mod;
            }

            base = (base * base) % mod;
            e /= 2;
        }
        return ans;
    }
};