#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        int N, B;
        cin >> N >> B;
        vector<int> price;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            price.push_back(tmp);
        }
        sort(price.begin(), price.end());
        for (int i = 0; i < N; i++) {
            if (price[i] <= B) {
                B -= price[i];
                answer++;
            } else {
                break;
            }
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
