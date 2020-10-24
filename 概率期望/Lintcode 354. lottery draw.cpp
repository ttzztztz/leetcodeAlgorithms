class Solution {
public:
    /**
     * @param b: 
     * @param c: 
     * @param p: 
     * @return: return the a
     */
    double lotteryDraw(int b, int _c, int _p) {
        // write your code here
        const double c = 1.0 * _c / 100.0, p = 1.0 * _p / 100.0;
        const double t = 1.0 / p;
        
        double l = 0.0, r = 1.0;
        while (abs(r - l) >= 1e-8) {
            const double m = (l + r) * 0.5;
            const double res = solve(m, b, c);
            
            if (abs(res - t) <= 1e-9) {
                return 100.0 * m;
            } else if (res > t - 1e-9) {
                l = m;
            } else {
                r = m;
            }
        }
        return l * 100.0;
    }
private:
    double solve(double a, int b, double c) {
        double ans = 0.0;
        
        double last = 1.0, p = a;
        for (int i = 1;; i++) {
            if (i < b) {
                ans += last * a * i;
                last *= (1.0 - a);
            } else { // i >= b
                p = min(p + c, 1.0);

                ans += last * p * i;
                last *= (1.0 - p);
            }
            if (p == 1.0) break;
        }
        return ans;
    }
};
