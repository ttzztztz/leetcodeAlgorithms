class Solution {
public:
    bool checkPowersOfThree(int n) {
        typedef long long ll;
        vector<ll> a;
        ll cur = 1;
        while (cur <= n) {
            a.push_back(cur);
            cur *= 3;
        }
        
        vector<int> t = {0};
        for (int i : a) {
            vector<int> g;
            for (int x : t) {
                g.push_back(x);
                g.push_back(x + i);
            }
            t = g;
        }
        
        unordered_set<int> f(t.begin(), t.end());
        return f.count(n);
    }
};
