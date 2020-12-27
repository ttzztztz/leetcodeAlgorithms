class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> se = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int a = 0, b = 0;
        for (int l = 0, r = s.size() / 2; r < s.size(); l++, r++) {
            if (se.count(s[l])) a++;
            if (se.count(s[r])) b++;
        }
        
        return a == b;
    }
};
