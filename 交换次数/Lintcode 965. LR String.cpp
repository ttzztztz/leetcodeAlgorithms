class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @param n: max times to swap a 'l' and a 'r'.
     * @return: return if s can transform to t.
     */
    bool LRString(string &s, string &t, int n) {
        const int m = s.size();
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> f1, f2;
        for (const char ch : s) f1[ch]++;
        for (const char ch : t) f2[ch]++;
        if (f1 != f2) return false;
        
        vector<int> f;
        for (int i = 0; i < m; i++) {
            if (s[i] == 'l') f.push_back(i);
        }
        
        vector<bool> visited(m, false);
        auto adv = [&](int i) -> int {
            i++;
            while (i < m && visited[i]) i++;
            return i;
        };
        
        for (int i = 0, j = 0, fptr = 0; i < m; i++) {
            if (t[i] == s[j]) {
                j = adv(j);
                if (t[i] == 'l') fptr++;
            } else if (t[i] == 'r') {
                return false;
            } else { // t[i] == 'l', s[i] == 'r'
                if (fptr >= f.size()) return false;
                n -= f[fptr] - i;
                visited[f[fptr]] = true;
                fptr++;
                if (n < 0) return false;
            }
        }
        return true;
    }
}; 
