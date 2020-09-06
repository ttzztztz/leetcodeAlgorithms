#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTreeNode {
public:
    int left, right;
    long long sum, lazyTag;

    SegmentTreeNode() : left(0), right(0), sum(0), lazyTag(0) {};
};

SegmentTreeNode treeNode[100500 * 4];

int L(int u) {
    return (u << 1);
}

int R(int u) {
    return (u << 1) + 1;
}

void pushUp(int u) {
    treeNode[u].sum = treeNode[L(u)].sum + treeNode[R(u)].sum;
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

void pushDown(int u) {
    if (!treeNode[u].lazyTag) {
        return;
    }

    treeNode[L(u)].sum += treeNode[u].lazyTag * (treeNode[L(u)].right - treeNode[L(u)].left + 1);
    treeNode[R(u)].sum += treeNode[u].lazyTag * (treeNode[R(u)].right - treeNode[R(u)].left + 1);

    treeNode[L(u)].lazyTag += treeNode[u].lazyTag;
    treeNode[R(u)].lazyTag += treeNode[u].lazyTag;

    treeNode[u].lazyTag = 0;
}

void update(int u, int left, int right, long long val) {
    if (left <= treeNode[u].left && treeNode[u].right <= right) {
        treeNode[u].sum += val * (treeNode[u].right - treeNode[u].left + 1);
        treeNode[u].lazyTag += val;
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

long long query(int u, int left, int right) {
    if (left <= treeNode[u].left && treeNode[u].right <= right) {
        return treeNode[u].sum;
    }

    long long answer = 0;
    pushDown(u);
    int middle = (treeNode[u].left + treeNode[u].right) >> 1;
    if (left <= middle) {
        answer += query(L(u), left, right);
    }
    if (middle < right) {
        answer += query(R(u), left, right);
    }
    return answer;
}

int main() {
    int N, M;
    cin >> N >> M;
    build(1, 1, N + 1);
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;

        update(1, i, i, tmp);
    }
    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long long x, y, k;
            cin >> x >> y >> k;
            update(1, x, y, k);
        } else {
            long long x, y;
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }

    return 0;
}