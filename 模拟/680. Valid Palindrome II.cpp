class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) return true;

        const int s_len = s.size();
        int i = 0, j = s_len - 1;
        while (i < j) {
            if (s[i] != s[j]) return is_palindrome(s, i, j - 1) || is_palindrome(s, i + 1, j);
            i++, j--;
        }
        return true;
    }
private:
    bool is_palindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
};