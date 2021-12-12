class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int maxn = 2e5 + 5, minn = -9999999999, n = fruits.size();
        typedef long long ll;
        vector<ll> l(maxn, minn), r(maxn, minn), pref(maxn, 0);
        
        for (int pos = 0, idx = 0; pos < maxn; pos++) {
            if (pos >= 1) {
                pref[pos] = pref[pos - 1];
            }
            
            if (idx < n && pos == fruits[idx][0]) {
                pref[pos] += fruits[idx][1];
                idx++;
            }
        }
        
        auto sum = [&](int l, int r) -> ll {
            ll ans = pref[r];
            if (l >= 1) ans -= pref[l - 1];
            return ans;
        };
        
        for (int i = 0; i < maxn; i++) {
            if (i <= startPos) {
                l[startPos - i] = sum(i, startPos);
            }
            
            if (startPos <= i) {
                r[i - startPos] = sum(startPos, i);
            }
        }
        
        for (int i = 0; i < maxn; i++) {
            if (l[i] == minn) {
                l[i] = sum(0, startPos);
            }
            
            if (r[i] == minn) {
                r[i] = sum(startPos, maxn - 1);
            }
        }
        
        ll ans = max(l[k], r[k]);
        for (int i = 0; k - 2 * i >= 0; i++) {
            ll t = 0;
            if (l[0] > 0) t = l[0];
            
            // cout << i << "," << r[i] << ", " << l[k - 2 * i] << "," << (k - 2 * i) << endl;
            ans = max(ans,
                     max(l[i] + r[k - 2 * i], r[i] + l[k - 2 * i]) - t
            );
        }
        
        return ans;
    }
};
