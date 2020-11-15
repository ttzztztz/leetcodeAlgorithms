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
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n, q;
        cin >> n >> q;

        int dist[30][30];
        memset(dist, 0x3f, sizeof dist);
        for (int i = 0; i < 26; i++) dist[i][i] = 1;

        typedef pair<string, int> Person;
        vector<Person> all;

        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;

            int state = 0;
            for (const char ch : name) state |= (1 << (ch - 'A'));
            all.emplace_back(name, state);

            const int m = name.size();
            for (int a = 0; a < m; a++) {
                for (int b = a + 1; b < m; b++) {
                    if (name[a] == name[b]) continue;

                    dist[name[a] - 'A'][name[b] - 'A'] = 2;
                    dist[name[b] - 'A'][name[a] - 'A'] = 2;
                }
            }
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j] - 1);
                }
            }
        }

        printf("Case #%d:", _);
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            const Person& p1 = all[a], p2 = all[b];
            if (p1.first == p2.first) {
                printf(" %d", 1);
            } else if (p1.second & p2.second) {
                printf(" %d", 2);
            } else {
                int mi = 0x3f3f3f3f;

                for (int x = 0; x < p1.first.size(); x++) {
                    for (int y = 0; y < p2.first.size(); y++) {
                        mi = min(mi, dist[p1.first[x] - 'A'][p2.first[y] - 'A']);
                    }
                }

                if (mi == 0x3f3f3f3f) printf(" %d", -1);
                else printf(" %d", mi + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
