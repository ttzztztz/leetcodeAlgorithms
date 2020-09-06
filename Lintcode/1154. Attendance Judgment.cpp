class Solution {
public:
    bool judge(string& s) {
        if (s.empty()) return false;
        
        int a = 0, contL = 0;
        for (const char ch : s) {
            if (ch == 'D') {
                a++;
                if (a >= 2) return true;
                contL = 0;
            } else if (ch == 'L') {
                contL ++;
                if (contL >= 3) return true;
            } else {
                contL = 0;
            }
        }
        
        return false;
    }
};
