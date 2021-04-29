class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            const int x = (a >> i) & 1;
            const int y = (b >> i) & 1;
            const int z = (c >> i) & 1;
            
            if (z == 1 && x == 0 && y == 0) {
                ans++;
            }
            if (z == 0) {
                ans += x + y;
            }
        }
        
        return ans;
    }
};