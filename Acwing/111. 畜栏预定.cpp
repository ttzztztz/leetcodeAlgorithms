#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 50005;
typedef pair<int, int> PII;
pair<PII, int> seg[N];
int id[N];
priority_queue<PII, vector<PII>, greater<>> heap;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first.first >> seg[i].first.second;
        seg[i].second = i;
    }
    sort(seg, seg + n);

    for (int i = 0; i < n; i++) {
        auto se = seg[i].first;
        if (heap.empty() || heap.top().first >= se.first) {
            id[seg[i].second] = heap.size() + 1;
            heap.emplace(se.second, heap.size() + 1);
        } else {
            auto front = heap.top();
            front.first = se.second;
            id[seg[i].second] = front.second;
            heap.pop();
            heap.push(front);
        }
    }

    cout << heap.size() << endl;
    for (int i = 0; i < n; i++) cout << id[i] << endl;
    return 0;
}
