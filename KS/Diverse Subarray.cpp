#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class TreeNode {
public:
    int left, right;
    int sum, prefixSum;

    TreeNode() : left(0), right(0), sum(0), prefixSum(0) {};
};

vector<int> types, prefix;
vector<vector<int>> position;
int N, S;
TreeNode node[401000];

void pushUp(int u) {
    node[u].sum = node[2 * u].sum + node[2 * u + 1].sum;
    node[u].prefixSum = max(
            node[2 * u].prefixSum,
            node[2 * u].sum + node[2 * u + 1].prefixSum);
}

void build(int u, int left, int right) {
    node[u].left = left, node[u].right = right;
    if (left == right) {
        node[u].sum = node[u].prefixSum = prefix[left];
        return;
    }

    const int middle = (left + right) >> 1;
    build(2 * u, left, middle);
    build(2 * u + 1, middle + 1, right);
    pushUp(u);
}

void update(int u, int key, int val) {
    if (node[u].left == node[u].right) {
        node[u].sum = node[u].prefixSum = val;
//        prefix[key] = val;
        return;
    }

    const int middle = (node[u].left + node[u].right) >> 1;
    if (key <= middle) update(2 * u, key, val);
    else update(2 * u + 1, key, val);
    pushUp(u);
}

void init() {
    types = prefix = vector<int>(100005, 0);
    position = vector<vector<int>>(100005, vector<int>{});

    memset(node, 0, sizeof(node));
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int answer = 0;
        cin >> N >> S;

        init();
        for (int i = 0; i < N; i++) {
            cin >> types[i];
            position[types[i]].push_back(i);
        }

        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j < position[i].size() && j < S; j++) {
                prefix[position[i][j]] = 1;
            }
            if (position[i].size() > S) {
                prefix[position[i][S]] = -S;
            }
        }

        build(1, 0, N - 1);
        answer = node[1].prefixSum;

        for (int i = 0; i < N; i++) {
            update(1, i, 0);

            int j = lower_bound(
                    position[types[i]].begin(),
                    position[types[i]].end(), i)
                    - position[types[i]].begin();

            if (position[types[i]].size() > j + S) {
                update(1, position[types[i]][j + S], 1);
            }
            if (position[types[i]].size() > j + S + 1) {
                update(1, position[types[i]][j + S + 1], -S);
            }
            answer = max(node[1].prefixSum, answer);
        }
        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}