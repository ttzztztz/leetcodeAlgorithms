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

long long answer = 0;
vector<int> P, T;
vector<int> nxt;
int lenT, lenP;

void build() {
    nxt[0] = -1;
    nxt[1] = 0;

    int j = 0, i = 1;
    while (i < lenP) {
        if (j == -1 || P[i] == P[j]) {
            nxt[++i] = ++j;
        } else {
            j = nxt[j];
        }
    }
}

void kmp() {
    int i = 0, j = 0;

    while (i < lenT) {
        if (j == -1 || T[i] == P[j]) {
            i++;
            j++;
        } else {
            j = nxt[j];
        }

        if (j == lenP) {
            answer++;
            j = nxt[j];
        }
    }
}


int main() {
    int Q;
    cin >> Q;
    for (int _ = 1; _ <= Q; _++) {
        answer = 0;
        int N, K;
        cin >> N >> K;
        vector<int> all;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            all.push_back(tmp);
        }

        P.clear();
        lenT = N;
        lenP = K;
        nxt = vector<int>(K + 5, 0);
        T = all;
        for (int i = K; i >= 1; i--) P.push_back(i);

        build();
        kmp();

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}