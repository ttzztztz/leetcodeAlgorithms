class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        typedef long long ll;
        vector<vector<ll>> b1(32, vector<ll>(2, 0)), b2(32, vector<ll>(2, 0));
        const int n = arr1.size(), m = arr2.size();
        int ans = 0;
        for (int i : arr1) {
            for (int j = 31; j >= 0; j--) {
                b1[j][(i & (1 << j)) ? 1 : 0] += 1;
            }
        }
        for (int i : arr2) {
            for (int j = 31; j >= 0; j--) {
                b2[j][(i & (1 << j)) ? 1 : 0] += 1;
            }
        }
        
        for (int i = 31; i >= 0; i--) {
            ll cnt = 1ll * b1[i][1] * b2[i][1];
            if (cnt % 2) ans += (1 << i);
        }
        return ans;
    }
};