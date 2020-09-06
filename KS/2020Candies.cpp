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

class SegmentTreeNode {
public:
    int left, right;
    long long all, part;

    SegmentTreeNode() : left(0), right(0), all(0), part(0) {};
};

SegmentTreeNode treeNode[300050 * 4];

int L(int u) {
    return (u << 1);
}

int R(int u) {
    return (u << 1) + 1;
}

void pushDown(int u) {

}

void pushUp(int u) {
    const int len_left = treeNode[L(u)].right - treeNode[L(u)].left + 1;

    if (len_left % 2 == 1) {
        treeNode[u].part = treeNode[L(u)].part - treeNode[R(u)].part;
    } else {
        treeNode[u].part = treeNode[L(u)].part + treeNode[R(u)].part;
    }

    if (len_left % 2 == 1) {
        treeNode[u].all = treeNode[L(u)].all - (treeNode[R(u)].all + len_left * treeNode[R(u)].part);
    } else {
        treeNode[u].all = treeNode[L(u)].all + (treeNode[R(u)].all + len_left * treeNode[R(u)].part);
    }
}

void build(int u, int left, int right) {
    treeNode[u].left = left;
    treeNode[u].right = right;

    if (left == right) {
        return;
    }

    int middle = (left + right) >> 1;
    build(L(u), left, middle);
    build(R(u), middle + 1, right);
    pushUp(u);
}

void update(int u, int left, int right, long long val) {
    if (left <= treeNode[u].left && treeNode[u].right <= right) {
        treeNode[u].part = val;
        treeNode[u].all = val;
        return;
    }

    pushDown(u);
    int middle = (treeNode[u].left + treeNode[u].right) >> 1;
    if (left <= middle) {
        update(L(u), left, right, val);
    }
    if (middle < right) {
        update(R(u), left, right, val);
    }
    pushUp(u);
}

pair<long long, int> query2(int u, int left, int right) {
    if (left <= treeNode[u].left && treeNode[u].right <= right) {
        return {treeNode[u].part, treeNode[u].right - treeNode[u].left + 1};
    }

    pushDown(u);
    int middle = (treeNode[u].left + treeNode[u].right) >> 1;

    long long l = 0, r = 0;
    int len_left = 0, len_right = 0;

    bool b1 = false, b2 = false;
    if (left <= middle) {
        auto p = query2(L(u), left, right);

        l = p.first;
        len_left = p.second;
        b1 = true;
    }
    if (middle < right) {
        auto p = query2(R(u), left, right);

        r = p.first;
        len_right = p.second;
        b2 = true;
    }

    long long answer = 0;

    if (b1 && b2) {
        if (len_left % 2 == 1) {
            answer = l - r;
        } else {
            answer = l + r;
        }
    } else if (b1) {
        answer = l;
    } else if (b2) {
        answer = r;
    }

    return {answer, len_left + len_right};
}

pair<long long, int> query(int u, int left, int right) {
    if (left <= treeNode[u].left && treeNode[u].right <= right) {
        return {treeNode[u].all, treeNode[u].right - treeNode[u].left + 1};
    }

    long long answer = 0;
    pushDown(u);
    int middle = (treeNode[u].left + treeNode[u].right) >> 1;

    long long l = 0, r = 0;
    long long r2 = 0;
    long long len_left = 0, len_right = 0;

    bool b1 = false, b2 = false;
    if (left <= middle) {
        auto p = query(L(u), left, right);
        l = p.first;
        len_left = p.second;

        b1 = true;
    }
    if (middle < right) {
        auto p = query(R(u), left, right);

        r = p.first;
        len_right = p.second;

        r2 = query2(R(u), left, right).first;
        b2 = true;
    }

    if (b1 && b2) {
        if (len_left % 2 == 1) {
            answer = l - (r + len_left * r2);
        } else {
            answer = l + (r + len_left * r2);
        }
    } else if (b1) {
        answer = l;
    } else if (b2) {
        answer = r;
    }

    return {answer, len_left + len_right};
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int N, Q;
        cin >> N >> Q;

        memset(treeNode, 0, sizeof treeNode);
        build(1, 1, N);
        for (int i = 0; i < N; i++) {
            long long tmp;
            cin >> tmp;
            update(1, i + 1, i + 1, tmp);
        }

        long long answer = 0;
        for (int i = 0; i < Q; i++) {
            char opt;
            int a, b;
            cin >> opt >> a >> b;

            if (opt == 'Q') {
                answer += query(1, a, b).first;

//                printf("%lld ", answer);
            } else if (opt == 'U') {
                update(1, a, a, b);
            }
        }
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}