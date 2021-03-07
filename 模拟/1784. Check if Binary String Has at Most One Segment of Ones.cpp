class Solution {
public:
    bool checkOnesSegment(string s) {
        const int n = s.size();
        
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i == 0 || s[i - 1] == '0') {
                    t++;
                }
            }
            
            if (t > 1) return false;
        }
        return true;
    }
};
