class Solution {
public:
    int integerBreak(int n) {
        int memo[] = {-1, -1, 1, 2, 4, 6, 9};
        if (n <= 6) {
            return memo[n];
        } else {
            int start = 0, index = 0;
            if (n % 3 == 1) {
                start = memo[4];
                index = 4;
            } else if (n % 3 == 2) {
                start = memo[5];
                index = 5;
            } else {
                start = memo[6];
                index = 6;
            }

            while (index < n) {
                start *= 3;
                index += 3;
            }
            return start;
        }
    }
};