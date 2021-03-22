class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> all;
        
        typedef long long ll;
        ll cur = 1;
        while (cur < 1e9) {
            string a = to_string(cur);
            sort(a.begin(), a.end());
            all.insert(a);
            cur *= 2;
        }
        
        string t = to_string(N);
        sort(t.begin(), t.end());
        return all.count(t);
    }
};
