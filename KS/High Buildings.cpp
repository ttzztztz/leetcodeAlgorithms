#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        
        if (a + b - c > n) {
            printf("Case #%d: IMPOSSIBLE\n", _);
            continue;
        }
        deque<int> h;
        if (n == 2) {
            if (a == 2 && b == 1 && c == 1) h = {1, 2};
            else if (a == 1 && b == 2 && c == 1) h = {2, 1};
            else if (a == 2 && b == 2 && c == 2) h = {1, 1};
            else {
                printf("Case #%d: IMPOSSIBLE\n", _);
                continue;
            }

            printf("Case #%d: ", _);
            for (int i : h) {
                printf("%d ", i);
            }
            printf("\n");
            continue;
        }

        for (int i = 0; i < c; i++) h.push_back(n);
        if (a + b - c < n) {
            if (a - c > 0) {
                for (int i = 0; i < (n - (a + b - c)); i++) h.push_front(1);
            } else if (b - c > 0) {
                for (int i = 0; i < (n - (a + b - c)); i++) h.push_back(1);
            } else {
                if (h.size() == 1) {
                    printf("Case #%d: IMPOSSIBLE\n", _);
                    continue;
                }
                h.pop_back();
                for (int i = 0; i < (n - (a + b - c)); i++) h.push_back(1);
                h.push_back(n);
            }
        }

        for (int i = 0; i < a - c; i++) h.push_front(2);
        for (int i = 0; i < b - c; i++) h.push_back(2);

        printf("Case #%d: ", _);
        for (int i : h) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
