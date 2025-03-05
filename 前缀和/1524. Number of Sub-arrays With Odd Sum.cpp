class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        if (arr.empty()) return 0;

        vector<int> cnt(2, 0);
        cnt[0] = 1;
        typedef long long ll;
        ll ans = 0;
        const int mod = 1e9+7;

        int cur = 0;
        for (int i = 0; i < arr.size(); i++) {
            cur = (cur + arr[i]) % 2;
            ans = (ans + cnt[cur ^ 1]) % mod;
            cnt[cur]++;
        }
        return ans;
    }
};