class Solution {
public:
    int maxDiff(int num) {
        string raw = to_string(num);
        
        string a = raw, b = raw;
        
        char p = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != '9') {
                p = a[i];
                break;
            }
        }
        if (p != 0) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == p) a[i] = '9';
            }
        }
        
        p = 0;
        bool first = false;
        for (int i = 0; i < b.size(); i++) {
            if (i == 0) {
                if (b[i] != '1') {
                    p = b[i];
                    first = true;
                    break;
                }
            } else {
                if (b[i] != '0' && b[i] != b[0]) {
                    p = b[i];
                    first = false;
                    break;
                }
            }
        }
        
        if (p != 0) {
            for (int i = 0; i < b.size(); i++) {
                if (b[i] == p) b[i] = first ? '1' : '0';
            }
        }
        
        return stol(a) - stol(b);
    }
};
