class Solution {
public:
    int valid(const string& s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            int x = s[i], y = s[i + 1];
            bool lowerx = false, lowery = false;
            if (x >= 'a' && x <= 'z') x -= 'a', lowerx = true;
            if (x >= 'A' && x <= 'Z') x -= 'A', lowerx = false;
            
            if (y >= 'a' && y <= 'z') y -= 'a', lowery = true;
            if (y >= 'A' && y <= 'Z') y -= 'A', lowery = false;
            
            if (x == y && ((lowerx && !lowery) || (!lowerx && lowery))) return i;
        }
        return -1;
    }
    string makeGood(string s) {
        int tmp;
        while ((tmp = valid(s)) != -1) {
            string nxt;
            for (int i = 0; i < s.size(); i++) {
                if (i == tmp || i == tmp + 1) continue;
                nxt.push_back(s[i]);
            }
            s = nxt;
        }
        
        return s;
    }
};
