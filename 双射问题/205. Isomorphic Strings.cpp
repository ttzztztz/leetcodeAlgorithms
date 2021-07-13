class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);
    }
private:
    bool check(const string& s, const string& t) {
        const int n = s.size();
        unordered_map<char, char> m;
        for (int i = 0; i < n; i++) {
            if (m.count(s[i]) && m[s[i]] != t[i]) return false;
            m[s[i]] = t[i];
        }
        return true;
    }
};