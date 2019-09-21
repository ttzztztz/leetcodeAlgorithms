#include <iostream>
#include <cstring>
#include <unordered_set>

//#define DEBUG 1

using namespace std;

class Edge {
public:
    int start, end, weight, next;

    Edge() : start(-1), end(-1), weight(0), next(-1) {};

    Edge(int s, int e, int w, int n) : start(s), end(e), weight(w), next(n) {};
};

Edge edge[2005], vertexNearestEdge[205];
int head[2005], edgeCount = 0;
bool visited[205];

void init(int V) {
    memset(head, 0xff, sizeof(head));
    memset(visited, 0, sizeof(visited));
    edgeCount = 0;

    for (int i = 1; i <= V; i++) {
        vertexNearestEdge[i] = Edge();
        edge[i] = Edge();
    }
}

void addEdge(int s, int e, int w) {
    edge[edgeCount] = Edge(s, e, w, head[s]);
    head[s] = edgeCount;
    edgeCount++;
}

void updateVertexNearestEdge(int s, int e, int w) {
    if (vertexNearestEdge[s].end == -1 || vertexNearestEdge[s].weight > w) {
        vertexNearestEdge[s].start = s;
        vertexNearestEdge[s].end = e;
        vertexNearestEdge[s].weight = w;
    }
}

void addEdgeDouble(int s, int e, int w) {
    addEdge(s, e, w);
    addEdge(e, s, w);
}

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;

    for (int i = head[u]; i != -1; i = edge[i].next) {
        const Edge &e = edge[i];
        dfs(e.end);
    }
}

int main() {
    int dataCount = 0;
    cin >> dataCount;

    for (int _ = 1; _ <= dataCount; _++) {
        int V = 0, E = 0;
        cin >> V >> E;

        init(V);
        unordered_set<int> zeroVertex;

        for (int i = 1; i <= E; i++) {
            int start = 0, end = 0, weight = 0;
            cin >> start >> end >> weight;

            updateVertexNearestEdge(end, start, weight);
            updateVertexNearestEdge(start, end, weight);

            if (weight == 0) {
                zeroVertex.insert(start);
                zeroVertex.insert(end);
            }
        }

        for (int i = 1; i <= V; i++) {
            const Edge &e = vertexNearestEdge[i];
            if (e.end != -1) {
                addEdgeDouble(e.start, e.end, e.weight);
            }
        }

        int sccCount = 0;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                sccCount++;
                dfs(i);
            }
        }

        int zeroConnectedVertexCount = 0;
        for (int i = 1; i <= V; i++) {
            const int end = vertexNearestEdge[i].end;
            if (zeroVertex.find(end) != zeroVertex.end()) {
                zeroConnectedVertexCount++;
#ifdef DEBUG
                cout << i << "," << end << endl;
#endif
            }
        }

        zeroConnectedVertexCount -= zeroVertex.size();
#ifdef DEBUG
        cout << sccCount << " " << zeroConnectedVertexCount << endl;
#endif

        long long answer = 1L << (sccCount + zeroConnectedVertexCount);
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}