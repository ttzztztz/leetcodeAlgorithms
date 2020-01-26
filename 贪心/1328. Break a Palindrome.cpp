class Solution {
public:
    bool isPalindrome(const string& s) {
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            if (s[i] != s[N - i - 1]) return false;
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        const int N = palindrome.size();
        if (N <= 1) {
            return "";
        }
        
        for (int i = 0; i < N; i++) {
            if (palindrome[i] != 'a') {
                const char prev = palindrome[i];
                palindrome[i] = 'a';
                if (!isPalindrome(palindrome)) return palindrome;
                palindrome[i] = prev;
            }
        }
        
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};
