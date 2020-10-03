class Solution {
public:
    /**
     * @param A: a list of integers
     * @param K: a integer
     * @return: return two integers
     */
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
        int p = 0, q = 1;
        double l = 0.0, r = 1.0;
        const int n = A.size();
        
        while (l <= r + 1e-8) {
            const double mid = 0.5 * (l + r);
            
            p = 0, q = 1;
            int cnt = 0;
            for (int ptr1 = 0, ptr2 = 0; ptr1 < n; ptr1++) {
                while (ptr2 < n && 1.0 * mid * A[ptr2] < 1.0 * A[ptr1] + 1e-8) ptr2++;
                
                cnt += n - ptr2;
                if (ptr2 < n && 1.0 * q * A[ptr1] + 1e-8 >= 1.0 * A[ptr2] * p) {
                    p = A[ptr1], q = A[ptr2];
                }
            }
            
            if (cnt == K) {
                return vector<int>{ p, q };
            } else if (cnt < K) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return vector<int>{ p, q };
    }
};
