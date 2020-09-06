class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k <= 1) return k;
        
        long long i = 1, j = 1;
        while (j <= k) {
            const long long next = i + j;
            i = j, j = next;
        }
        
        return 1 + findMinFibonacciNumbers(k - i);
    }
};
