class Edge {
public:
    int v, weight;

    Edge() : v(0), weight(0) {};

    Edge(int _v, int w) : v(_v), weight(w) {};

    bool operator<(const Edge &$2) const {
        return this->weight > $2.weight;
    }
};

class FullEdge {
public:
    int u, v, weight, head;

    FullEdge() : u(0), v(0), weight(0), head(0) {};

    FullEdge(int _u, int _v, int w, int h) : u(_u), v(_v), weight(w), head(h) {};
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int answer = 0, visitedVertex = 0;

        vector<bool> visited(N + 5, false);
        vector<int> head(N + 5, -1);
        vector<FullEdge> edge;

        for (const vector<int> &time : times) {
            edge.emplace_back(time[0], time[1], time[2], head[time[0]]);
            head[time[0]] = edge.size() - 1;
        }

        priority_queue<Edge> queue;
        queue.push(Edge(K, 0));
        while (!queue.empty()) {
            Edge e;
            do {
                e = queue.top();
                queue.pop();
            } while (!queue.empty() && visited[e.v]);

            if (!visited[e.v]) {
                visited[e.v] = true;
                answer = std::max(answer, e.weight);
                visitedVertex++;

                for (int i = head[e.v]; i != -1; i = edge[i].head) {
                    queue.push(Edge(edge[i].v, e.weight + edge[i].weight));
                }
            }
        }

        return ((visitedVertex == N) ? answer : -1);
    }
};