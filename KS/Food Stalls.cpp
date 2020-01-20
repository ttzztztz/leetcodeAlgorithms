#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Position {
public:
    long long x, c;

    Position() : x(0), c(0) {};

    Position(long long _x, long long _c) : x(_x), c(_c) {};
};

const long long MAX = 1e15 + 5;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = numeric_limits<long long>::max();
        int K, N;
        cin >> K >> N;
        vector<long long> X(N + 5, 0), C(N + 5, 0);
        for (int i = 1; i <= N; i++) cin >> X[i];
        for (int i = 1; i <= N; i++) cin >> C[i];

        vector<Position> positionList(N + 1);
        for (int i = 1; i <= N; i++) {
            positionList[i] = {X[i], C[i]};
        }
        sort(positionList.begin() + 1, positionList.end(), [](const Position &$1, const Position &$2) -> bool {
            return $1.x < $2.x;
        });

        vector<long long> f(N + 5, MAX), g(N + 5, MAX);
        long long sum_left = 0, sum_right = 0;
        priority_queue<long long, vector<long long>, less<>> queue;
        queue.push(numeric_limits<long long>::min());

        const int len_left = (K / 2), len_right = K - (K / 2);
        for (int i = 1; i <= len_left; i++) {
            const long long V = positionList[N].x - positionList[i].x + positionList[i].c;
            queue.push(V);
            sum_left += V;
        }

        for (int i = len_left + 1; i <= N; i++) {
            f[i] = sum_left - (positionList[N].x - positionList[i].x) * len_left;

            const long long V = positionList[N].x - positionList[i].x + positionList[i].c;
            if (queue.top() > V) {
                if (queue.top() != numeric_limits<long long>::min()) {
                    sum_left -= queue.top();
                }
                sum_left += V;
                queue.pop();
                queue.push(V);
            }
        }

        while (!queue.empty()) queue.pop();
        queue.push(numeric_limits<long long>::min());

        for (int i = 1; i <= len_right; i++) {
            const long long V = positionList[N - i + 1].x - positionList[1].x + positionList[N - i + 1].c;
            queue.push(V);
            sum_right += V;
        }

        for (int i = len_right + 1; i <= N; i++) {
            g[N - i + 1] = sum_right - (positionList[N - i + 1].x - positionList[1].x) * len_right;

            const long long V = positionList[N - i + 1].x - positionList[1].x + positionList[N - i + 1].c;
            if (queue.top() > V) {
                if (queue.top() != numeric_limits<long long>::min()) {
                    sum_right -= queue.top();
                }
                sum_right += V;
                queue.pop();
                queue.push(V);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (f[i] >= MAX || g[i] >= MAX) continue;
            answer = min(answer, f[i] + g[i] + positionList[i].c);
        }
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}