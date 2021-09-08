class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        const int mod = 26;
        const int n = shifts.size();
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % mod;
        }
        
        for (int i = 0; i < n; i++) {
            int d = s[i] - 'a';
            s[i] = ((d + shifts[i]) % mod) + 'a';
        }
        return s;
    }
};