#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n;
        string s;
        cin >> n >> s;

        printf("Case #%d: ", _);
        for (char ch : s) {
            if (ch == 'E') printf("S");
            else printf("E");
        }
        printf("\n");
    }

    return 0;
}
