class Solution {
public:
    bool squareIsWhite(string coordinates) {
        const int a = coordinates[0] - 'a', b = coordinates[1] - '0';
        return (a + b) % 2 == 0;
    }
};
