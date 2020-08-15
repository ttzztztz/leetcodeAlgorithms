class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        
        unordered_map<char, string> a;
        unordered_map<string, char> b;
        int i = 0;
        
        string s;
        while (ss >> s) {
            if (i >= pattern.size()) return false;
            const char ch = pattern[i];
            i++;

            if (s.empty()) return false;
            
            if (a.count(ch) && a[ch] != s) return false;
            if (!a.count(ch)) a[ch] = s;
            
            if (b.count(s) && b[s] != ch) return false;
            if (!b.count(s)) b[s] = ch;
        }
        
        return i >= pattern.size();
    }
};