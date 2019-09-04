class Matrix {
public:
    unsigned int number[3][3];

    Matrix() {
        number[1][1] = 0;
        number[1][2] = 0;
        number[2][1] = 0;
        number[2][2] = 0;
    }

    void setI() {
        number[1][1] = 1;
        number[1][2] = 0;
        number[2][1] = 0;
        number[2][2] = 1;
    }
};

Matrix operator*(Matrix &$1, Matrix &$2) {
    Matrix matrix;

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 2; k++) {
                matrix.number[i][j] += $1.number[i][k] * $2.number[k][j];
            }
        }
    }

    return std::move(matrix);
}

class Solution {
public:
    int climbStairs(int n) {
        Matrix pow;
        pow.number[1][1] = 1;
        pow.number[1][2] = 1;
        pow.number[2][1] = 1;
        pow.number[2][2] = 0;

        Matrix base;
        base.setI();

        while (n) {
            if (n & 1) {
                base = base * pow;
            }
            pow = pow * pow;
            n >>= 1;
        }

        return base.number[1][1];
    }
};