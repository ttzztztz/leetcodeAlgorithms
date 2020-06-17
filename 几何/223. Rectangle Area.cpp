class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const long long x = max(0ll, 1ll * min(C, G) - 1ll * max(A, E));
        const long long y = max(0ll, 1ll * min(D, H) - 1ll * max(B, F));
        
        const long long f = x * y;
        
        const long long S1 = (C - A) * (D - B), S2 = (G - E) * (H - F);
        
        const long long answer = S1 + S2 - f;
        return answer;
    }
};
