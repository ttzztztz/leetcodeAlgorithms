class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for (const char c : s) ch ^= c;
        for (const char c : t) ch ^= c;
        return ch;
    }
};
