#include <iostream>
#include <set>

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;

    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0, K = 0;
        cin >> N >> K;

        multiset<int> expireSet;
        for (int i = 1; i <= N; i++) {
            int expires = 0;
            cin >> expires;
            expireSet.insert(expires);
        }

        int answer = 0;
        auto it = expireSet.begin();

        int nowDate = 0, nowExpire = K;
        while (it != expireSet.end()) {
            int expireDate = *it;

            bool needBreak = false;
            while (it != expireSet.end() && expireDate <= nowDate) {
                it++;
                if (it == expireSet.end()) {
                    needBreak = true;
                    break;
                } else {
                    expireDate = *it;
                }
            }
            if (needBreak) {
                break;
            }

            if (nowExpire > 0) {
                nowExpire--;
                answer++;
                it++;
            } else {
                nowExpire = K;
                nowDate++;
            }
        }

        printf("Case #%d: %d \n", _, answer);
    }

    return 0;
}