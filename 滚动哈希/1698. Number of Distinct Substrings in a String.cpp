class Solution {
public:
    int countDistinct(string s) {
        if (s.empty()) return 0;

        vector<ll> pref = {0}, base = {1};
        for (int i = 0; i < s.size(); i++) {
            pref.push_back((pref.back() * 26 + s[i] - 'a') % kMod);
            base.push_back((base.back() * 26) % kMod);
        }
        
        int ans = 0;
        for (int len = 1; len <= s.size(); len++) {
            unordered_set<ll> hash_list;
            for (int l = 0; l + len - 1 < s.size(); l++) {
                const int r = l + len - 1;
                const ll hash = (pref[r + 1] - ((pref[l] * base[len]) % kMod) + kMod) % kMod;

                hash_list.insert(hash);
            }
            ans += hash_list.size();
        }
        return ans;
    }
private:
    typedef long long ll;
    const int kMod = 1e9+9;
};
