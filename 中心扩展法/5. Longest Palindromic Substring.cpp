class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            auto [l1, r1] = longest_palidrome(s, i, i);
            if (r1 - l1 + 1 > ans.size()) ans = s.substr(l1, r1 - l1 + 1);

            if (i + 1 < n && s[i] == s[i + 1]) {
                auto [l2, r2] = longest_palidrome(s, i, i + 1);
                if (r2 - l2 + 1 > ans.size()) ans = s.substr(l2, r2 - l2 + 1);
            }
        }
        
        return ans;
    }
private:
    pair<int, int> longest_palidrome(const string& s, int i, int j) {
        const int n = s.size();
        while (i >= 0 && j < n) {
            if (s[i] == s[j]) {
                i--, j++;
            } else {
                break;
            }
        }

        return { i + 1 , j - 1 };
    }
};