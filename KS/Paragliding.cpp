#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto sortFunc = [](const pair<int, int> &$1, const pair<int, int> &$2) -> bool {
    if ($1.first == $2.first) {
        return $1.second > $2.second;
    } else {
        return $1.first > $2.first;
    }
};

int main() {
    int testCase = 0;
    cin >> testCase;

    for (int _ = 1; _ <= testCase; _++) {
        int answer = 0, N = 0, K = 0;
        cin >> N >> K;
        //<-- generate data
        vector<long long> p(N + 5, 0), h(N + 5, 0), x(K + 5, 0), y(K + 5, 0);
        int A1, B1, C1, M1, A2, B2, C2, M2, A3, B3, C3, M3, A4, B4, C4, M4;
        cin >> p[1] >> p[2] >> A1 >> B1 >> C1 >> M1;
        cin >> h[1] >> h[2] >> A2 >> B2 >> C2 >> M2;
        cin >> x[1] >> x[2] >> A3 >> B3 >> C3 >> M3;
        cin >> y[1] >> y[2] >> A4 >> B4 >> C4 >> M4;
        for (int i = 3; i <= N; i++) {
            p[i] = (A1 * p[i - 1] + B1 * p[i - 2] + C1) % M1 + 1;
            h[i] = (A2 * h[i - 1] + B2 * h[i - 2] + C2) % M2 + 1;
        }
        for (int i = 3; i <= K; i++) {
            x[i] = (A3 * x[i - 1] + B3 * x[i - 2] + C3) % M3 + 1;
            y[i] = (A4 * y[i - 1] + B4 * y[i - 2] + C4) % M4 + 1;
        }
        //<-- solve
        vector<pair<long long, long long>> balloonList, towerList;
        for (int i = 1; i <= N; i++) {
            towerList.emplace_back(p[i] + h[i], h[i] - p[i]);
        }
        for (int i = 1; i <= K; i++) {
            balloonList.emplace_back(x[i] + y[i], y[i] - x[i]);
        }

        std::sort(towerList.begin(), towerList.end(), sortFunc);
        std::sort(balloonList.begin(), balloonList.end(), sortFunc);

        long long towerMaxHeight = -999999999;
        int ptr = 0;
        for (int i = 0; i < K; i++) {
            while (ptr < N && towerList[ptr].first >= balloonList[i].first) {
                towerMaxHeight = std::max(towerMaxHeight, towerList[ptr].second);
                ptr++;
            }

            if (towerMaxHeight >= balloonList[i].second) {
                answer++;
            }
        }
        //<-- output
        printf("Case #%d: %d \n", _, answer);
    }
    return 0;
}