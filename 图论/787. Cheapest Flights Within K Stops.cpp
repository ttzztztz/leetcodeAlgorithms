class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int MAX = 0x6f6f6f6f;
        vector<vector<int>> map(105, vector<int>(105, MAX));
        vector<int> dist(105, MAX);

        for (const vector<int>& flight : flights) {
            map[flight[0]][flight[1]] = flight[2];
        }

        dist[src] = 0;

        for (int _ = 0; _ <= K; _++) {
            vector<int> temp = dist;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (map[i][j] != MAX && temp[j] > dist[i] + map[i][j]) {
                        temp[j] = dist[i] + map[i][j];
                    }
                }
            }
            dist = temp;
        }

        return dist[dst] == MAX ? -1 : dist[dst];
    }
};