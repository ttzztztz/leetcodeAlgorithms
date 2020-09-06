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

typedef pair<int, int> PII;

long long f[100005];
void init() {
    memset(f, 0, sizeof f);
}
int lowbit(int i) {
    return i & (-i);
}
long long query(int i) {
    long long answer = 0;
    while (i) {
        answer += f[i];
        i -= lowbit(i);
    }
    return answer;
}
void inc(int k, long long v) {
    while (k && k <= 100002) {
        f[k] += v;
        k += lowbit(k);
    }
}

class Item {
public:
    long long E, R;
    int i;
};

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;
        vector<Item> a(n, {0, 0, 0});
        for (int i = 0; i < n; i++) {
            cin >> a[i].E >> a[i].R;
            a[i].i = i + 1;
        }

        sort(a.begin(), a.end(), [](const auto& $1, const auto& $2) -> bool {
            if ($1.E + $1.R != $2.E + $2.R) return $1.E + $1.R > $2.E + $2.R;
            if ($1.R != $2.R) return $1.R > $2.R;
            return $1.i < $2.i;
        });
        long long total = 0;
        for (auto& i : a) total += i.E;
        long long sum = total;

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (total - a[i].E < a[i].R) {
                total -= a[i].E;
            } else {
                ok = true;
                printf("Case #%d: %d INDEFINITELY\n", _, i);
                break;
            }
        }
        if (ok) continue;

        total = sum;
        priority_queue<PII, vector<PII>, greater<>> heap;
        int idx = 0, curRemoveCnt = 0, removeCnt = 0;
        long long answer = sum;
        init();
        for (auto& p : a) {
            inc(p.i, p.E);
        }

        while (idx < n && total - a[idx].E < a[idx].R) {
            heap.emplace(a[idx].i, idx);
            idx++;
        }

        while (!heap.empty()) {
            int i, j;
            tie(i, j) = heap.top();
            heap.pop();

            inc(i, -a[j].E);
            if (total + query(i) > answer) {
                answer = total + query(i);
                removeCnt = curRemoveCnt;
            }
            curRemoveCnt++;
            total -= a[j].E;

            while (idx < n && total - a[idx].E < a[idx].R) {
                heap.emplace(a[idx].i, idx);
                idx++;
            }
        }

        printf("Case #%d: %d %lld\n", _, removeCnt, answer);
    }
    return 0;
}
