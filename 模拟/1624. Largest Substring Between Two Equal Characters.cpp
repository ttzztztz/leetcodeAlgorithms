class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) ans = max(ans, j - i - 1);
            }
        }
        return ans;
    }
};
