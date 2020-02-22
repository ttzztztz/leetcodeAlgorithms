class Solution {
public:
    /**
     * @param n: a string
     * @return: return a string
     */
    string smallestGoodBase(string &n) {
        long long N = stol(n);
        long long answer = N - 1;
        
        const long long pL = 2, pR = log2(N + 1);
        for (long long p = pL; p <= pR; p++) {
            long long left = 2, right = pow(N + 1, 1.0 / (p - 1));
            while (left <= right) {
                const long long mid = (left + right) >> 1;
                const long long ans = (pow(mid, p) - 1) / (mid - 1);
                
                if (ans < N) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            const long long _p = pow(left, p);
            const long long div = (_p - 1) / (left - 1);
            const long long mod = (_p - 1) % (left - 1);
            if (div == N && mod == 0) {
                answer = min(answer, left);
            }
        }
        
        return to_string(answer);
    }
};
