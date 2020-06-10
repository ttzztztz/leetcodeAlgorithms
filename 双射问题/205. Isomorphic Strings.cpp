class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return solve(s, t) && solve(t, s);
    }
private:
    bool solve(const string& s, const string& t) {
        const int N = s.size(), M = t.size();
        if (N != M) return false;
        
        unordered_map<char, char> replace;
        for (int i = 0; i < N; i++) {
            if (replace.count(s[i])) {
                if (replace[s[i]] != t[i]) return false;
            } else {
                replace[s[i]] = t[i];
            }
        }
        return true;
    }
};
