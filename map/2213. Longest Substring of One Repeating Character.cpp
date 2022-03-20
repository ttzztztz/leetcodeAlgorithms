class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        const int n = s.size(), q = queryCharacters.size();
        
        map<int, int> f;
        multiset<int> g;
        for (int i = 1, last_l = 0; i <= n; i++) {
            if (s[i] == s[last_l]) {
                continue;
            } else {
                f[last_l] = i - 1;
                g.insert(i - last_l);
                last_l = i;
            }
        }
        
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            const int t = queryIndices[i];
            const char ch = queryCharacters[i];
            // cout << ch << "," << t << endl;
            
            if (ch != s[t]) {
                auto it_self = --f.upper_bound(t);
                int l = it_self->first, r = it_self->second;
                g.erase(g.find(r - l + 1));
                
                if (l == t) {
                    if (l + 1 <= r) {
                        f[l + 1] = r;
                        g.insert(r - l);
                    }
                    f.erase(it_self);
                } else { // l < t
                    f[l] = t - 1;
                    g.insert(t - l);
                    if (t + 1 <= r) {
                        f[t + 1] = r;
                        g.insert(r - t);
                    }
                }
                
                l = t, r = t;
                if (t - 1 >= 0 && s[t - 1] == ch) {
                    auto it = --f.upper_bound(t - 1);
                    l = min(l, it->first);
                    
                    // cout << "erase" << it->first << "," << it->second << endl;
                    g.erase(g.find(it->second - it->first + 1));
                    f.erase(it);
                }
                if (t + 1 < n && ch == s[t + 1]) {
                    auto it = f.lower_bound(t + 1);
                    r = max(r, it->second);
                    
                    // cout << "erase" << it->first << "," << it->second << endl;
                    g.erase(g.find(it->second - it->first + 1));
                    f.erase(it);
                }
                
                g.insert(r - l + 1);
                // cout << "insert" << l << "," << r << endl;
                f[l] = r;
            }
            
            ans[i] = *g.rbegin();
            s[t] = ch;
            // for (auto[k,v] : f) cout << k << "," << v << " ";
            // cout << endl;
        }
        return ans;
    }
};
