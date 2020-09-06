class Solution {
public:
    int arrangeCoins(int n) {
        int answer = 0, row = 1;
        while (n > 0) {
            n -= row;
            if (n < 0) break;
            row++;
            answer++;
        }
        return answer;
    }
};