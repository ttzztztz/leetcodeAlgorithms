#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

typedef long double LD;
vector<LD> frac, two;

void init() {
    frac.push_back(0.0);
    two.push_back(0.0);
    for (int i = 1; i <= 2e5 + 5; i++) {
        frac.push_back(frac[i - 1] + log((LD) i));
        two.push_back(two[i - 1] + log((LD) 2.0));
    }
}

long double calcC(int n, int m) {
    return frac[n] - frac[m] - frac[n - m];
}

int main() {
    init();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long double answer = 0;
        int W, H;
        int L, U, R, D;
        cin >> W >> H >> L >> U >> R >> D;

        if (D < H) {
            for (int i = 1; i <= L - 1; i++) {
                answer += exp(calcC(D + i - 2, D - 1) - two[D + i - 1]);
            }
        }

        if (R < W) {
            for (int i = 1; i <= U - 1; i++) {
                answer += exp(calcC(i + R - 2, R - 1) - two[i + R - 1]);
            }
        }

        printf("Case #%d: %Lf\n", _, answer);
    }
    return 0;
}
