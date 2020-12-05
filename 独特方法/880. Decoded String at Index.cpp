class Solution {
public:
    string decodeAtIndex(string S, int K) {
        const int n = S.size();
        typedef unsigned long long ull;
        ull len = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                len++;
                if (K == len) {
                    return string(1, S[i]);
                }
            } else { // S[i] >= '0' && S[i] <= '9'
                const int t = S[i] - '0';
                
                if (len * t >= K) {
                    if (K % len == 0) {
                        return decodeAtIndex(S.substr(0, i), len);
                    } else {
                        return decodeAtIndex(S.substr(0, i), K % len);
                    }
                } else {
                    len *= t;
                }
            }
        }
        
        return ""; // K >= decode(S).size()
    }
};
