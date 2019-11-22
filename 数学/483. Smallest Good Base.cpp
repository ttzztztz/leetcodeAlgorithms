class Solution {
public:
    string smallestGoodBase(string n) {
        long long N = stol(n);
        long long answer = N - 1;
        for (int p = 1; p <= 59; p++) {
            const int k = pow(N, 1.0 / p);
            if (k <= 1) {
                continue;
            }

            long long temp = 1, mul = 1;
            for (int i = 1; i <= p; i++) {
                mul *= k;
                temp += mul;
            }

            if (temp == N) {
                return to_string(k);
            }
        }
        return to_string(answer);
    }
};