class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();

        int ans_l = -1, ans_r = -1;
        for (int i = 0; i < n; i++) {
            auto [i1, j1] = longest_palindromic(s, i, i);
            if (i1 == -1) continue;
            if (ans_l == -1 || j1 - i1 > ans_r - ans_l) {
                ans_l = i1, ans_r = j1;
            }

            if (i + 1 < n && s[i] == s[i + 1]) {
                auto [i2, j2] = longest_palindromic(s, i, i + 1);
                if (i2 == -1) continue;
                if (ans_l == -1 || j2 - i2 > ans_r - ans_l) {
                    ans_l = i2, ans_r = j2;
                }
            }
        }

        string ans;
        if (ans_l == -1) return "";
        for (int i = ans_l; i <= ans_r; i++) ans += s[i];
        return ans;
    }
private:
    pair<int, int> longest_palindromic(const string& s, int i, int j) {
        const int n = s.size();
        while (i >= 0 && j < n) {
            if (s[i] != s[j]) break;
            else i--, j++;
        }

        if (i + 1 > j - 1) return { -1, -1 };
        return { i + 1, j - 1 };
    }
};