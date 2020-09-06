#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef pair<double, double> PDD;
PDD offset[1005];
double INF = 1e10, EPS = 1e-6;

int main() {
    int n;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (y > d) {
            cout << -1 << endl;
            exit(0);
        }

        double p = sqrt(d * d - y * y);
        offset[i] = {x - p, x + p};
    }

    sort(offset, offset + n, [](const PDD& $1, const PDD $2)->bool {
        return $1.second < $2.second;
    });
    double last = -INF;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (offset[i].first >= last + EPS) {
            answer++;
            last = offset[i].second;
        }
    }
    cout << answer << endl;
    return 0;
}
