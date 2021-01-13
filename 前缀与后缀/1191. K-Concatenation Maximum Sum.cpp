class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        typedef long long ll;
        const int mod = 1e9+7;
        
        ll cur = 0, ans = 0;
        for (int i : arr) {
            cur = max((ll) i, cur + i);
            ans = max(ans, cur);
        }
        
        if (k >= 2) {
            const long long sum = accumulate(arr.begin(), arr.end(), 0);
            long long max_pref = 0, max_suf = 0;
            
            cur = 0;
            for (int i : arr) {
                cur += i;
                max_pref = max(max_pref, cur);
            }

            cur = 0;
            for (int i = arr.size() - 1; i >= 0; i--) {
                cur += arr[i];
                max_suf = max(max_suf, cur);
            }

            ans = max(ans, max_pref + max_suf + max(0ll, sum * (k - 2)));
        }
        
        return ans % mod;
    }
};
