#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define DEBUG 1

class Edge {
public:
    int start, end;

    Edge() : start(0), end(0) {};

    Edge(int s, int e) : start(s), end(e) {};
};

const int MAX = 20;
int edge[MAX][MAX];
vector<Edge> validEdge;
bool vertexUsed[MAX];
long long answer = 0;

void init() {
    answer = 0;
    memset(edge, 0, sizeof(edge));
    memset(vertexUsed, 0, sizeof(vertexUsed));
    validEdge.clear();
}

void dfs(int current, int max, int sum, int vertexCount) {
    if (vertexCount >= 3 && 2 * max < sum) {
        answer++;
    }

    for (int i = current; i < validEdge.size(); i++) {
        const Edge &e = validEdge[i];
        int start = e.start, end = e.end;
        if (!vertexUsed[start] && !vertexUsed[end]) {
            vertexUsed[start] = vertexUsed[end] = true;

            dfs(i, std::max(max, edge[start][end]), sum + edge[start][end], vertexCount + 1);

            vertexUsed[start] = vertexUsed[end] = false;
        }
    }
}

int main() {
    int testCases = 0;
    cin >> testCases;
    for (int _ = 1; _ <= testCases; _++) {
        init();

        // <-- input
        int N = 0;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> edge[i][j];
                if (i < j && edge[i][j] > 0) {
                    validEdge.emplace_back(i, j);
                }
            }
        }
        // <-- solve
        dfs(0 ,0, 0, 0);

        // <-- output
        printf("Case #%d: %lld \n", _, answer);
    }

    return 0;
}