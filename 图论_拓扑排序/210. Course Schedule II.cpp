class Edge {
public:
    int start, end, next;
    Edge(): start(0), end(0), next(-1) {};
    Edge(int s, int e, int n): start(s), end(e), next(n) {};
};

class Solution {
public:
    void addEdge(int s, int e, int* head, Edge* edge, int& edgeCount) {
        edge[edgeCount] = Edge(s, e, head[s]);
        head[s] = edgeCount;
        edgeCount++;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int answer = 0;
        bool haveRequirements[numCourses], visited[numCourses];
        int head[numCourses], edgeCount = 0, inDegree[numCourses];
        Edge edge[numCourses * 4];

        vector<int> orderList;

        memset(haveRequirements, 0, sizeof(haveRequirements));
        memset(head, 0xff, sizeof(head));
        memset(inDegree, 0, sizeof(inDegree));
        memset(visited, 0, sizeof(visited));

        for (const vector<int>& require: prerequisites) {
            int first = require[0], second = require[1];
            haveRequirements[first] = haveRequirements[second] = true;

            addEdge(second, first, head, edge, edgeCount);
            inDegree[first]++;
        }

        //<-- top sort
        deque<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (haveRequirements[i] == false) {
                orderList.push_back(i);
                answer++;
            }
            if (haveRequirements[i] && inDegree[i] == 0) {
                queue.push_back(i);
            }
        }

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();

            orderList.push_back(u);
            for (int i = head[u]; i != -1; i = edge[i].next) {
                const int v = edge[i].end;
                if (!visited[v]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) {
                        visited[v] = true;
                        queue.push_back(v);
                    }
                }
            }

            answer++;
        }

        if (answer == numCourses) {
            return orderList;
        } else {
            return vector<int>();
        }
    }
};