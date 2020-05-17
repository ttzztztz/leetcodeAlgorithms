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

string answer;
string tmp;
unordered_set<char> cur;
unordered_set<char> all;
vector<string> f;
int N;
int R, C;

void init() {
    answer.clear();
    tmp.clear();
    cur.clear();
    all.clear();
    f.clear();
    N = 0;
}

bool dfs(char ch) {
    tmp.push_back(ch);
    cur.insert(ch);

    for (int i = R - 2; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            if (f[i][j] != ch) continue;

            if (f[i + 1][j] != ch && !cur.count(f[i + 1][j])) {
                tmp.pop_back();
                cur.erase(ch);
                return false;
            }
        }
    }

    if (cur.size() == N) {
        answer = tmp;
        return true;
    }

    for (char nx : all) {
        if (cur.count(nx)) continue;
        if (dfs(nx)) return true;
    }

    tmp.pop_back();
    cur.erase(ch);
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        cin >> R >> C;
        init();
        f = vector<string>(R);

        for (int i = 0; i < R; i++) {
            cin >> f[i];
            for (int j = 0; j < C; j++) {
                all.insert(f[i][j]);
            }
        }

        N = all.size();
        for (char ch : all) {
            if (dfs(ch)) break;
        }

        printf("Case #%d: %s\n", _, answer.empty() ? "-1" : answer.c_str());
    }
    return 0;
}