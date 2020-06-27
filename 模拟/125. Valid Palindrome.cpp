class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for (const char ch : s) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) tmp += ch;
        }
        
        for (int l = 0, r = tmp.size() - 1; l < r; l++, r--) {
            char ch1 = tmp[l], ch2 = tmp[r];
            if (ch1 >= 'A' && ch1 <= 'Z') ch1 = ch1 - 'A' + 'a';
            if (ch2 >= 'A' && ch2 <= 'Z') ch2 = ch2 - 'A' + 'a';
            
            if (ch1 != ch2) return false;
        }
        return true;
    }
};
