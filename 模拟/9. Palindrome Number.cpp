class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        ss << x;
        string str1;
        ss >> str1;
        for (int i = 0; i < str1.size(); i++) {
            int j = str1.size() - i - 1;

            if (str1[i] != str1[j]) {
                return false;
            }
        }

        return true;
    }
};