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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }
        int answer = 0;
        bool haveRequirements[numCourses], visited[numCourses];
        int head[numCourses], edgeCount = 0, inDegree[numCourses];
        Edge edge[numCourses * 4];

        memset(haveRequirements, 0, sizeof(haveRequirements));
        memset(head, 0xff, sizeof(head));
        memset(inDegree, 0, sizeof(inDegree));
        memset(visited, 0, sizeof(visited));

        for (const vector<int>& require: prerequisites) {
            int first = require[0], second = require[1];
            haveRequirements[first] = haveRequirements[second] = true;

            addEdge(first, second, head, edge, edgeCount);
            inDegree[second]++;
        }

        //<-- top sort
        deque<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (haveRequirements[i] == false) {
                answer++;
            }
            if (haveRequirements[i] && inDegree[i] == 0) {
                queue.push_back(i);
            }
        }

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();

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

        return answer == numCourses;
    }
};