#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // freopen("./case.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> appear;
    for (int i = 0; i < n; i++) appear[arr[i]] = i;

    sort(arr.begin(), arr.end());
    int ans = 0, idx = n;
    for (int i = 0; i + 1 < n; i++) {
        if (appear[arr[i]] > appear[arr[i + 1]]) {
            appear[arr[i + 1]] = idx++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}