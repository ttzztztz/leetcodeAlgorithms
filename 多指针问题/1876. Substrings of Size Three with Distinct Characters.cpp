class Solution {
public:
    int countGoodSubstrings(string s) {
        const int n = s.size();
        int ans = 0;
        
        if (s.size() <= 2) return 0;
        unordered_map<char, int> c;
        for (int i = 0; i < 3; i++) c[s[i]]++;
        if (c.size() == 3) ans++;
        
        for (int l = 0, r = 3; r < n; l++, r++) {
            c[s[r]]++;
            c[s[l]]--;
            if (c[s[l]] == 0) c.erase(s[l]);
            
            if (c.size() == 3) ans++;
        }
        return ans;
    }
};