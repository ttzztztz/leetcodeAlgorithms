#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

int main() {
    double n, l, r;
    cin >> n >> l >> r;
    vector<double> k(n + 1);
    for (int i = n; i >= 0; i--) cin >> k[i];

    auto fn = [&](double x) -> double {
        double ans = 0.0;
        for (int i = n; i >= 0; i--) {
            ans += k[i] * pow(x, i);
        }
        return ans;
    };

    while (abs(r - l) >= 1e-5) {
        const double margin = (r - l) / 3.0;
        const double ml = l + margin, mr = r  - margin;

        const double sl = fn(ml), sr = fn(mr);
        if (sl <= sr) l = ml;
        if (sr <= sl) r = mr;
    }

    cout << l << endl;
    return 0;
}