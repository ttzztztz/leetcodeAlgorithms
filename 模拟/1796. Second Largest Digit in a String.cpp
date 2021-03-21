class Solution {
public:
    int secondHighest(string s) {
        set<int> t;
        for (const char ch : s) {
            if ('0' <= ch && ch <= '9') {
                const int m = ch - '0';
                t.insert(m);
            }
        }
        
        if (t.size() < 2) return -1;
        else {
            vector<int> x(t.begin(), t.end());
            return x[x.size() - 2];
        }
    }
};
