class Solution {
public:
    bool isPalindrome(const string& s) {
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            if (s[i] != s[N - i - 1]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        if (isPalindrome(s)) return 1;
        return 2;
    }
};
