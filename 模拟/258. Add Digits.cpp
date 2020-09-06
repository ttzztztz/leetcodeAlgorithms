class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int t = num, a = 0;
            while (t) {
                a += t % 10;
                t /= 10;
            }
            
            num = a;
        }
        return num;
    }
};
