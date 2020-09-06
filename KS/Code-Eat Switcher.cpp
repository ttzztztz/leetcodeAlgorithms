#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Request {
public:
    int i;
    long long code, eat;

    Request() : i(0), code(0), eat(0) {};

    Request(int _i, long long c, long long e) : i(_i), code(c), eat(e) {};
};

class Slot {
public:
    long long code, eat;

    Slot() : code(0), eat(0) {};

    Slot(long long c, long long e) : code(c), eat(e) {};
};

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int D, S;
        cin >> D >> S;
        vector<Request> request(D + 1);
        vector<Slot> slot(S + 1);

        vector<bool> answer(D + 1, false);
        for (int i = 1; i <= S; i++) cin >> slot[i].code >> slot[i].eat;
        for (int i = 1; i <= D; i++) {
            request[i].i = i - 1;
            cin >> request[i].code >> request[i].eat;
        }

        sort(request.begin() + 1, request.end(), [](const Request &$1, const Request &$2) -> bool {
            return $1.code < $2.code;
        });
        sort(slot.begin() + 1, slot.end(), [](const Slot &$1, const Slot &$2) -> bool {
            return $1.code * $2.eat > $2.code * $1.eat;
        });

        vector<long long> prefixCodeSum(S + 5, 0), suffixEatSum(S + 5, 0);
        for (int i = 1; i <= S; i++) {
            prefixCodeSum[i] = prefixCodeSum[i - 1] + slot[i].code;
        }
        for (int i = S; i >= 1; i--) {
            suffixEatSum[i] = suffixEatSum[i + 1] + slot[i].eat;
        }

        int ptr = 0;
        for (int i = 1; i <= D; i++) {
            const Request& r = request[i];
            while (ptr + 1 <= S && prefixCodeSum[ptr + 1] < r.code) ptr++;

            if (ptr == S) {
                if (r.code == prefixCodeSum[S]) {
                    answer[r.i] = r.eat == 0;
                } else {
                    answer[r.i] = false;
                }
                continue;
            }

            const long long restCode = r.code - prefixCodeSum[ptr];
            const long long restEat = r.eat - suffixEatSum[ptr + 2];

            answer[r.i] = restCode * slot[ptr + 1].eat <=
                          slot[ptr + 1].eat * slot[ptr + 1].code - restEat * slot[ptr + 1].code;
        }

        printf("Case #%d: ", _);
        for (int i = 0; i < D; i++) printf("%c", answer[i] ? 'Y' : 'N');
        printf("\n");
    }
    return 0;
}
