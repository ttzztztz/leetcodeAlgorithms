class Solution {
public:
    int brokenCalc(long long X, long long Y) {
        if (Y <= X) {
            return X - Y;
        }
        
        if (Y % 2 == 1) {
            return brokenCalc(X, Y + 1) + 1;
        } else {
            return brokenCalc(X, Y / 2) + 1;
        }
    }
};
