class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n) {
            const int digit = n % 10;
            sum += digit, product *= digit;
            n /= 10;
        }
        return product - sum;
    }
};