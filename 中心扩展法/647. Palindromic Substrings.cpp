class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += count(s, i, i);
            if (i + 1 < s.size()) ans += count(s, i, i + 1);
        }
        return ans;
    }
private:
    int count(const string& s, int i, int j) {
        int ans = 0;
        while (i >= 0 && j < s.size()) {
            if (s[i] == s[j]) {
                i--, j++, ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};