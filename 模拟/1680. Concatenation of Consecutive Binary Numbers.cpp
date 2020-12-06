class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9+7;
        
        typedef unsigned long long ull;
        ull x = 1;
        for (int i = 2; i <= n; i++) {
            const int t = bits(i);
            x = (x << t) % mod;
            x = (x + i) % mod;
        }
        return x;
    }
private:
    int bits(int x) {
        for (int i = 31; i >= 0; i--) {
            if (x & (1 << i)) return i + 1;
        }
        return 1;
    }
};
