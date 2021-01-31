class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        const int q = queries.size();
        vector<bool> ans(q, false);
        
        typedef long long ll;
        vector<ll> pref = {0};
        for (int i : candiesCount) pref.push_back(pref.back() + i);
        
        for (int i = 0; i < q; i++) {
            const ll t = queries[i][0], d = queries[i][1], cap = queries[i][2];
            const ll l = d + 1, r = cap * d + cap;

            ans[i] = max(pref[t] + 1, l) <= min(r, pref[t + 1]);
        }
        return ans;
    }
};
