class Solution {
public:
    /**
     * @param a: Left margin
     * @param b: Right margin
     * @return: return the greatest common multiple
     */
    long long greatestcommonmultiple(int a, int b) {
        long long answer = 0;
        
        for (int k = 0; k <= 5; k++) {
            for (int m = 0; m <= 5; m++) {
                for (int j = 0; j <= 5; j++) {
                    if (b - k >= a && b - m >= a && b - j >= a) {
                        answer = max(answer, lcm(b - j, b - k, b - m));
                    }
                }
            }
        }
        
        return answer;
    }
private:
    long long lcm(long long a, long long b) {
        return a * b / __gcd(a, b);
    }
    long long lcm(long long a, long long b, long long c) {
        return lcm(lcm(a, b), c);
    }
};
