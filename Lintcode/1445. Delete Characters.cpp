class Solution {
public:
    /**
     * @param s: The string s
     * @param t: The string t
     * @return: Return if can get the string t
     */
    bool canGetString(string &s, string &t) {
        // Write your code here
        const int n = s.size(), m = t.size();
        int ptr1 = 0, ptr2 = 0;
        while (ptr2 < m) {
            while (ptr1 < n && s[ptr1] != t[ptr2]) ptr1++;
            if (ptr1 >= n) return false;
            ptr1++, ptr2++;
        }
        
        return ptr2 == m;
    }
};
