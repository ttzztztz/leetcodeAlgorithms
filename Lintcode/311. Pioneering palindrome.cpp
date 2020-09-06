class Solution {
public:
    /**
     * @param s: A string containing only uppercase and lowercase letters
     * @return: Judge whether it can become a palindrome
     */
    bool isPalindrome(string &s) {
        unordered_map<char, int> app;
        for (const char ch : s) app[ch]++;
        
        bool one = false;
        for (auto& p : app) {
            if (p.second % 2 == 1) {
                if (one) return false;
                else one = true;
            }
        }
        return true;
    }
};