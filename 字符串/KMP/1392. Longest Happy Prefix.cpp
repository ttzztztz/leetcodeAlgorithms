class Solution {
public:
    string longestPrefix(string s) {
        const int n = s.size();
        vector<int> next(n + 1, -1);
        next[1] = 0;
        int i = 1, j = 0;
        while (i < n) {
            if (j == -1 || s[i] == s[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        return s.substr(0, next[n]);
    }
};