class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = s.size(), m = t.size();
        int ptr2 = 0;
        for (int ptr1 = 0; ptr1 < n; ptr1++) {
            while (ptr2 < m && s[ptr1] != t[ptr2]) {
                ptr2++;
            }

            if (ptr2 < m && s[ptr1] == t[ptr2]) {
                ptr2++;
            } else {
                return false;
            }
        }
        return true;
    }
};