#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> TII;
typedef pair<int, int> PII;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int N;
        cin >> N;
        vector<TII> allActivity;
        vector<char> assign(N);

        bool valid = true;
        for (int i = 0; i < N; i++) {
            int start, end;
            cin >> start >> end;
            end--;
            allActivity.emplace_back(start, end, i);
        }

        sort(allActivity.begin(), allActivity.end());
        priority_queue<PII, vector<PII>, greater<>> heap;
        for (int i = 0; i < N; i++) {
            int start, end, index;
            tie(start, end, index) = allActivity[i];

            if (heap.empty() || heap.top().first >= start) {
                if (heap.size() == 2) {
                    valid = false;
                    break;
                }

                assign[index] = heap.empty() ? 'C' : 'J';
                heap.emplace(end, assign[index]);
            } else {
                int fEnd, fAssign;
                tie(fEnd, fAssign) = heap.top();

                assign[index] = fAssign;
                heap.pop();
                fEnd = end;
                heap.emplace(fEnd, fAssign);
            }
        }

        printf("Case #%d: ", _);
        if (!valid) {
            printf("IMPOSSIBLE");
        } else {
            for (int i = 0; i < N; i++) printf("%c", assign[i]);
        }
        printf("\n");
    }

    return 0;
}
