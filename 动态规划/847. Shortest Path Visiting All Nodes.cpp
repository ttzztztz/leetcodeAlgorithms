class Node{
public:
    int state, node, dist;
    Node() : state(0), node(0), dist(0) {};
    Node(int s, int n, int d) : state(s), node(n), dist(d) {};
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() <= 1) {
            return 0;
        }
        const int N = graph.size(), mask = (1 << N) - 1;
        int answer = 999999;
        for (int start = 0; start < N; start++) {
            deque<Node> queue;
            vector<vector<bool>> visited(15, vector<bool>(1 << 15, false));

            visited[start][0] = true;
            queue.emplace_back(0, start, 0);
            while (!queue.empty()) {
                Node node = queue.front();
                queue.pop_front();

                if (node.state == mask) {
                    answer = min(answer, node.dist);
                    // queue.clear();
                    break;
                }

                for (int i = 0; i < graph[node.node].size(); i++) {
                    const int nextNode = graph[node.node][i], nextState = (node.state | (1 << nextNode));
                    if (visited[nextNode][nextState]) {
                        continue;
                    }
                    visited[nextNode][nextState] = true;
                    queue.emplace_back(nextState, nextNode, node.dist + 1);
                }
            }
        }
        return answer - 1;
    }
};