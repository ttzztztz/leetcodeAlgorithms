#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

class Edge {
public:
    int start, end, next;

    Edge() : start(0), end(0), next(-1) {};

    Edge(int s, int e, int n) : start(s), end(e), next(n) {};
};

const int MAX = 2005;
Edge edge[MAX * 2];
Edge newEdge[MAX * 2];
int head[MAX * 2], newHead[MAX * 2];
int edgeCount = 0, newEdgeCount = 0;
bool visited[MAX], inCircle[MAX];
int answer[MAX];

int dfs(int u, int last) {
    visited[u] = true;

    for (int i = head[u]; i != -1; i = edge[i].next) {
        const Edge &e = edge[i];
        if (e.end == last) {
            continue;
        }

        if (visited[e.end]) {
            inCircle[e.end] = true;
            inCircle[u] = true;

            visited[u] = false;
            return e.end;
        } else {
            int result = dfs(e.end, u);
            if (result != -1) {
                inCircle[u] = true;
                visited[u] = false;

                return result == u ? -1 : result;
            }
        }
    }

    visited[u] = false;
    return -1;
}

void init() {
    memset(head, 0xff, sizeof(head));
    memset(newHead, 0xff, sizeof(newHead));
    memset(answer, 0x6f, sizeof(answer));
    memset(inCircle, 0, sizeof(inCircle));
    memset(visited, 0, sizeof(visited));
    edgeCount = 0;
    newEdgeCount = 0;
}

void addEdge(int start, int end, int &targetEdgeCount, Edge *targetEdgeArr, int *headArr) {
    targetEdgeArr[targetEdgeCount] = Edge(start, end, headArr[start]);
    headArr[start] = targetEdgeCount;
    targetEdgeCount++;
}

void addEdgeDouble(int start, int end, int &targetEdgeCount, Edge *targetEdgeArr, int *headArr) {
    addEdge(start, end, targetEdgeCount, targetEdgeArr, headArr);
    addEdge(end, start, targetEdgeCount, targetEdgeArr, headArr);
}

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        init();
        int N = 0;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            int start = 0, end = 0;
            cin >> start >> end;
            addEdgeDouble(start, end, edgeCount, edge, head);
        }

        // <-- circle dfs
        dfs(1, -1);
        // <-- rebuild
        for (int i = 0; i < edgeCount; i++) {
            const Edge &e = edge[i];
            if (inCircle[e.start] && inCircle[e.end]) {
                continue;
            }

            addEdgeDouble(inCircle[e.start] ? N + 1 : e.start,
                          inCircle[e.end] ? N + 1 : e.end,
                          newEdgeCount,
                          newEdge,
                          newHead
            );
        }
        // <-- bfs
        deque<pair<int, int>> queue;
        queue.emplace_back(N + 1, 0);
        memset(visited, 0, sizeof(visited));
        while (!queue.empty()) {
            pair<int, int> item = queue.front();
            int vertex = item.first;
            int dist = item.second;
            queue.pop_front();

            for (int i = newHead[vertex]; i != -1; i = newEdge[i].next) {
                const Edge &e = newEdge[i];
                if (!visited[e.end]) {
                    visited[e.end] = true;
                    answer[e.end] = dist + 1;
                    queue.emplace_back(e.end, dist + 1);
                } else {
                    answer[e.end] = std::min(answer[e.end], dist + 1);
                }
            }
        }

        printf("Case #%d: ", _);
        for (int i = 1; i <= N; i++) {
            if (inCircle[i]) {
                printf("0 ");
            } else {
                printf("%d ", answer[i]);
            }
        }
        printf("\n");
    }
}