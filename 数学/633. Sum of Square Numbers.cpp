class Solution {
public:
    bool judgeSquareSum(int c) {
        typedef long long ll;
        for (ll i = 0; i <= sqrt(c) + 1; i++) {
            const ll r = c - i * i;
            if (r < 0) continue;
            const ll b = sqrt(r);
            if (b * b == r) return true;
        }
        return false;
    }
};
