class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n + 5, vector<int>(n + 5, 1234567));
        for (const vector<int>& e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int answer = 1005, id = -1;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) temp++;
            }
            
            if (temp < answer) {
                answer = temp;
                id = i;
            } else if (temp == answer) {
                id = max(id, i);
            }
        }
        return id;
    }
};
