class Solution {
public:
    int N;
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> xMap, yMap, xDiagonal, yDiagonal;
        set<pair<int, int>> haveLights;
        
        for (const vector<int>& lamp : lamps) {
            xMap[lamp[0]]++;
            yMap[lamp[1]]++;
            xDiagonal[lamp[0] + lamp[1]]++;
            yDiagonal[lamp[1] - lamp[0]]++;
            
            haveLights.emplace(lamp[0], lamp[1]);
        }
        
        const int Q = queries.size();
        vector<int> answer(Q, 0);
        
        const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1, 0};
        const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};
        
        for (int i = 0; i < Q; i++) {
            const int x = queries[i][0], y = queries[i][1];
            
            if (xMap[x] > 0 || yMap[y] > 0 || xDiagonal[x + y] > 0 || yDiagonal[y - x] > 0) {
                answer[i] = 1;
            } else {
                answer[i] = 0;
            }
            
            for (int k = 0; k < 9; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (haveLights.count({nx, ny})) {
                    haveLights.erase({nx, ny});
                    
                    xMap[nx]--;
                    yMap[ny]--;
                    xDiagonal[nx + ny]--;
                    yDiagonal[ny - nx]--;
                }
            }
        }
        return answer;
    }
};
