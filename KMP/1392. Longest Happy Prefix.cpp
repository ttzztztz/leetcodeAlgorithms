class Solution {
public:
    string longestPrefix(string s) {
        const int N = s.size();
        vector<int> next(N + 2, 0);
        next[0] = -1, next[1] = 0;
        
        int i = 1, j = 0;
        while (i <= N) {
            if (j == -1 || s[i] == s[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        
        return s.substr(0, next[N]);
    }
};
