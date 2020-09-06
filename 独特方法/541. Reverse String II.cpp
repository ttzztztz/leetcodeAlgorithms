class Solution {
public:
    string reverseStr(string s, int k) {
        const int N = s.size();
        
        for (int i = 0; i < N; i += 2 * k) {
            int l = i, r = (i + k - 1 < N) ? (i + k - 1) : (N - 1);
            
            reverse(s.begin() + l, s.begin() + r + 1);
        }
        
        return s;
    }
};