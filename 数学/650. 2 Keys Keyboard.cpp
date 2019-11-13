class Solution {
public:
    int minSteps(int n) {
        int answer = 0;

        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                answer += i;
                n /= i;
            }
        }

        return answer;
    }
};