#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        string str;
        cin >> str;
        const int N = str.size();
        str = "0" + str + "0";

        string answer;
        for (int i = 1; i <= N + 1; i++) {
            const int d = str[i] - str[i - 1];
            string tmp;
            if (d > 0) {
                tmp = string(d, '(');
            } else if (d < 0) {
                tmp = string(-d, ')');
            }

            answer += tmp;
            if (i <= N) {
                answer += str[i];
            }
        }

        printf("Case #%d: ", _);
        printf("%s", answer.c_str());
        printf("\n");
    }

    return 0;
}
