class Solution {
public:
    bool checkString(string s) {
        int state = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && state == 1) return false;
            if (s[i] == 'b') state = 1;
        }
        return true;
    }
};
