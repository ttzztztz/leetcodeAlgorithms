class Solution {
public:
    int findTheWinner(int n, int k) {
        int cur = 0;
        for(int i = 2; i <= n; i++) {
            cur = (cur + k) % i;
        }
        return cur + 1;
    }
};
