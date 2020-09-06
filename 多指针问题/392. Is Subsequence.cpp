class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        const int N = s.size(), M = t.size();
        while (i < N && j < M) {
            if (s[i] == t[j]) {
                i++, j++;
            } else {
                j++;
            }
        }
        
        return i == N;
    }
};
