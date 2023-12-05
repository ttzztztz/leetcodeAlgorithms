class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            const int matches = n / 2;
            ans += matches;
            n -= matches;
        }
        return ans;
    }
};