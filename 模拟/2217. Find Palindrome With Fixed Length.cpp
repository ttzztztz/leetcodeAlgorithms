class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        const int q = queries.size();
        vector<ll> ans(q, -1);
        const int t = intLength - intLength / 2;

        ll start = 1;
        for (int i = 0; i < t - 1; i++) start *= 10ll;
        ll end = start * 10ll;
        
        for (int i = 0; i < q; i++) {
            const ll f = queries[i];
            const ll p = start + f - 1;
            if (p >= end) continue;
            
            ans[i] = pick(to_string(p), intLength);
        }
        
        return ans;
    }
private:
    typedef long long ll;
    
    ll pick(string u, int il) {
        string ans = u;
        if (il % 2 == 1) u.pop_back();
        reverse(u.begin(), u.end());
        ans += u;
        
        return stoll(ans);
    }
};
