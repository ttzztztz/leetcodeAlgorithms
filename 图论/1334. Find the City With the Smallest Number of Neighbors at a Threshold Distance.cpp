class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int m = edges.size();
        vector<vector<int>> dist(n, vector<int>(n, 9999999));
        
        for (auto& edge : edges) {
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dist[i][j] > distanceThreshold) continue;
                
                ind[i]++, ind[j]++;
            }
        }
        
        int ans = 0, ans_ind = n + 5;
        for (int i = n - 1; i >= 0; i--) {
            if (ind[i] < ans_ind) {
                ans_ind = ind[i];
                ans = i;
            }
        }
        return ans;
    }
};