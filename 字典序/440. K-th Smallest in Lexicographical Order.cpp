class Solution {
public:
    int findKthNumber(int n, int k) {
        long long current = 1;
        while (k > 1) {
            const long long sum = calcSum(current, n);
            if (sum >= k) {
                k--;
                current *= 10;
            } else {
                k -= sum;
                current++;
            }
        }
        return current;
    }
private:
    long long calcSum(long long current, long long n) {
        long long answer = 0, tmp = 1;
        while (current <= n) {
            answer += min(tmp, n - current + 1);
            tmp *= 10;
            current *= 10;
        }
        return answer;
    }
};
