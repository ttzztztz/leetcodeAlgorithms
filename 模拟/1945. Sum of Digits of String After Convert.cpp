class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> cur;
        for (const char ch : s) {
            const int d = ch - 'a' + 1;
            
            if (d < 10) cur.push_back(d);
            else cur.push_back(d % 10), cur.push_back(d / 10);
        }
        
        for (int i = 0; i < k - 1; i++) {
            vector<int> nxt;
            int u = accumulate(cur.begin(), cur.end(), 0);
            while (u) {
                nxt.push_back(u % 10);
                u /= 10;
            }
            cur = nxt;
        }
        return accumulate(cur.begin(), cur.end(), 0);
    }
};