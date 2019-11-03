class Edge {
public:
    int start, end, next;
    Edge() : start(0), end(0), next(-1) {};
    Edge(int s, int e, int n) : start(s), end(e), next(n) {};
};

class Solution {
public:
    vector<int> head;
    vector<Edge> edge;
    int maxVertex;
    int farthest, farthestDist;
    void build(vector<vector<int>>& edges) {
        maxVertex = 0;

        int edgeCount = 0;
        head = vector<int>(10005, -1);
        for (vector<int>& e : edges) {
            edge.push_back(Edge(e[0], e[1], head[e[0]]));
            head[e[0]] = edgeCount;
            edgeCount++;

            edge.push_back(Edge(e[1], e[0], head[e[1]]));
            head[e[1]] = edgeCount;
            edgeCount++;

            maxVertex = max(maxVertex, e[0]);
            maxVertex = max(maxVertex, e[1]);
        }
    }
    int dfs(vector<bool>& visited, int u, int dist) {
        int answer = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            const Edge e = edge[i];
            if (visited[e.end]) {
                continue;
            }
            visited[e.end] = true;
            answer = max(dfs(visited, e.end, dist + 1) + 1, answer);
            visited[e.end] = false;
        }
        if (answer == 0 && dist > farthestDist) {
            farthest = u;
            farthestDist = dist;
        }
        return answer;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        build(edges);

        vector<bool> visited(10005, false);
        visited[0] = true;
        farthestDist = 0;
        dfs(visited, farthest = 0, 0);

        farthestDist = 0;
        visited = vector<bool>(10005, false);

        return dfs(visited, farthest, 0);
    }
};