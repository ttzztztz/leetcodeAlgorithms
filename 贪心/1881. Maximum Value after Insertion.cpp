class Solution {
public:
    string maxValue(string n, int x) {
        string ans;
        const int len = n.size();
        
        int negative = 0;
        if (n[0] == '-') {
            n.erase(n.begin());
            negative = 1;
        }
        
        const char t = '0' + x;
        bool inserted = false;
        for (int i = 0; i < len; i++) {
            if (
                (negative == 0 && x > (n[i] - '0'))
                || (negative == 1 && x < (n[i] - '0'))
            ) {
                ans = n.substr(0, i) + t;
                if (i < len) ans += n.substr(i);
                
                inserted = true;
                break;
            }
        }
        
        if (!inserted) {
            ans = n + t;
        }
        if (negative) ans = "-" + ans;
        return ans;
    }
};