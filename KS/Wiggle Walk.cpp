#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> Point;
Point src;
map<pair<char, Point>, Point> dirMap;

void init() {
    dirMap.clear();
}
Point find(Point p, char dir) {
    if (dirMap.count({dir, p})) {
        return dirMap[{dir, p}];
    }

    if (dir == 'N') {
        p.first--;
    } else if (dir == 'S') {
        p.first++;
    } else if (dir == 'E') {
        p.second++;
    } else {
        p.second--;
    }

    return p;
}

void merge(Point p) {
    Point n = find(p, 'N');
    Point s = find(p, 'S');
    Point e = find(p, 'E');
    Point w = find(p, 'W');

    dirMap[{'N', s}] = n;
    dirMap[{'S', n}] = s;
    dirMap[{'E', w}] = e;
    dirMap[{'W', e}] = w;
}

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N, R, C;
        init();
        cin >> N >> R >> C >> src.first >> src.second;

        for (int i = 0; i < N; i++) {
            char opt;
            cin >> opt;

            merge(src);
            src = find(src, opt);
        }
        printf("Case #%d: %d %d\n", _, src.first, src.second);
    }
    return 0;
}