class Solution {
public:
    int maximum69Number (int num) {
        int ans = num, cur = num, d = 1;
        for (int i = 0; i < 5; i++) {
            const int t = cur % 10;
            cur /= 10;
            
            int tmp = num;
            if (t == 6) {
                tmp += 3 * d;
                ans = max(ans, tmp);
            }
            
            d *= 10;
        }
        return ans;
    }
};