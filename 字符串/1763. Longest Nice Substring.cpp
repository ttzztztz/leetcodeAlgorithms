class Solution {
public:
    string longestNiceSubstring(string s) {
        const int n = s.size();
        for (int len = n; len >= 1; len--) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                
                bool ok = true;
                unordered_set<char> v;
                for (int t = i; t <= j; t++) v.insert(s[t]);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (v.count(ch) && !v.count(ch - 'a' + 'A')) {
                        ok = false;
                        break;
                    }
                }
                
                for (char ch = 'A'; ch <= 'Z'; ch++) {
                    if (v.count(ch) && !v.count(ch - 'A' + 'a')) {
                        ok = false;
                        break;
                    }
                }
                
                if (ok) {
                    return s.substr(i, len);
                }
            }
        }
        return "";
    }
};
