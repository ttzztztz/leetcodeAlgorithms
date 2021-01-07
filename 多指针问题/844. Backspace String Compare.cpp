class Solution {
public:
    bool backspaceCompare(string S, string T) {
        const int n = S.size(), m = T.size();
        int l = n - 1, r = m - 1;
        while (true) {
            int mov = 0;
            while (l >= 0 && (S[l] == '#' || mov > 0)) {
                if (S[l] == '#') {
                    mov++;
                } else {
                    mov--;
                }
                l--;
            }
            mov = 0;
            while (r >= 0 && (T[r] == '#' || mov > 0)) {
                if (T[r] == '#') {
                    mov++;
                } else {
                    mov--;
                }
                r--;
            }
            
            if (l >= 0 && r >= 0 && S[l] == T[r]) {
                l--, r--;
            } else {
                break;
            }
        }
        
        return l == -1 && r == -1;
    }
};
