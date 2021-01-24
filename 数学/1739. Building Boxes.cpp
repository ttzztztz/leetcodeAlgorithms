class Solution {
public:
    int minimumBoxes(int tt) {
        typedef long long ll;
        
        ll n = tt;
        ll rest = 0, last_a = 0, comp = 0;
        for (int i = 1; i <= 2000; i++) {
            ll a = 1ll * i * (i + 1) * (i + 2) / 6;
            
            if (a > n) {
                break;
            } else {
                comp = a - last_a;
                last_a = a;
                rest = n - a;
            }
        }
        
        long long t = 0;
        while (rest > 0) {
            rest -= t + 1;
            t++;
        }
        
        return comp + t;
    }
};
