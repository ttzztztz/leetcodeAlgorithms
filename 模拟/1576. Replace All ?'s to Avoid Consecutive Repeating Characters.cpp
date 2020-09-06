class Solution {
public:
    string modifyString(string s) {
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') continue;
            
            unordered_set<char> vis;
            if (i - 1 >= 0) vis.insert(s[i - 1]);
            if (i + 1 < n) vis.insert(s[i + 1]);
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (vis.count(c)) continue;
                s[i] = c;
                break;
            }
        }
        
        return s;
    }
};
