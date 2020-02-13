class Solution {
public:
    /**
     * @param x: The end points set of edges
     * @param y: The end points set of edges
     * @param d: The length of edges
     * @return: Return the index of the fermat point
     */
    vector<vector<int>> edge;
    map<pair<int, int>, long long> weight;
    vector<long long> dist;
    vector<int> size;
    int N, answerPoint;
    long long answer;
    
    int getFermatPoint(vector<int> &x, vector<int> &y, vector<int> &d) {
        const int M = x.size();
        N = 0;
        
        for (int i = 0; i < M; i++) {
            N = max(N, x[i]);
            N = max(N, y[i]);
        }
        
        answerPoint = N;
        answer = numeric_limits<long long>::max();
        
        edge = vector<vector<int>>(N + 1, vector<int>{});
        dist = vector<long long>(N + 1, 0);
        size = vector<int>(N + 1, 0);
        
        for (int i = 0; i < M; i++) {
            edge[x[i]].push_back(y[i]);
            edge[y[i]].push_back(x[i]);
            
            weight[{x[i], y[i]}] = d[i];
            weight[{y[i], x[i]}] = d[i];
        }
        
        dfs1(1, -1);
        dfs2(1, -1);
        return answerPoint;
    }
private:
    void dfs1(int u, int parent) {
        size[u] = 1;
        for (int v : edge[u]) {
            if (v == parent) continue;
            
            dfs1(v, u);
            size[u] += size[v];
            dist[1] += weight[{u, v}];
        }
    }
    void dfs2(int u, int parent) {
        for (int v : edge[u]) {
            if (v == parent) continue;
            
            dist[v] = dist[u] + weight[{u, v}] * (N - 2 * size[v]);
            dfs2(v, u);
        }
        
        if (dist[u] < answer) {
            answerPoint = u;
            answer = dist[u];
        } else if (dist[u] == answer) {
            answerPoint = min(answerPoint, u);
        }
    }
};
