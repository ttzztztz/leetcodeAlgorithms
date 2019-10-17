class MinEdge {
public:
    int start, end, weight, next;
    MinEdge() : start(0), end(0), weight(0), next(-1) {};
    MinEdge(int s, int e, int w, int n) : start(s), end(e), weight(w), next(n) {};
};

class Solution {
public:
    int answer = -1, dest, K;
    vector<bool> visited;
    vector<int> head;
    vector<MinEdge> edge;
    void dfs(int u, int layer, int cost) {
        if (layer <= K + 2 && u == dest) {
            if (answer == -1) {
                answer = cost;
            } else {
                answer = std::min(answer, cost);
            }

            return;
        }
        if (layer > K + 2 || (cost > answer && answer != -1)) {
            return;
        }

        visited[u] = true;

        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (visited[edge[i].end]) {
                continue;
            }
            dfs(edge[i].end, layer + 1, cost + edge[i].weight);
        }

        visited[u] = false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        visited = vector<bool>(100005, false);
        this->dest = dst;
        this->K = K;

        edge = vector<MinEdge>(100005, MinEdge());
        head = vector<int>(100005, -1);
        for (int i = 0; i < flights.size(); i++) {
            static int edgeCount = 0;

            edge[edgeCount] = MinEdge(flights[i][0], flights[i][1], flights[i][2], head[flights[i][0]]);
            head[flights[i][0]] = edgeCount;
            edgeCount++;
        }

        dfs(src, 1, 0);
        return this->answer;
    }
};