class Solution {
public:
    int totalMoney(int n) {
        int x = n / 7, y = n % 7;
        const int full = (49 + 7 * x) * x / 2;
        const int rest = (2 * x + y + 1) * y / 2;
        return full + rest;
    }
};