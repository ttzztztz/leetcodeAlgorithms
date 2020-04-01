class Solution {
public:
    /**
     * @param equations: 
     * @param values: 
     * @param queries: 
     * @return: return a double type array
     */
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        const int N = equations.size(), M = queries.size();
        
        unordered_map<string, int> id;
        int idCnt = 0;
        for (const vector<string>& s : equations) {
            if (!id.count(s[0])) {
                id[s[0]] = idCnt++;
            }
            if (!id.count(s[1])) {
                id[s[1]] = idCnt++;
            }
        }
        
        vector<vector<double>> edge(idCnt, vector<double>(idCnt));
        vector<vector<bool>> visited(idCnt, vector<bool>(idCnt, false));
        for (int i = 0; i < N; i++) {
            const int u = id[equations[i][0]], v = id[equations[i][1]];
            edge[u][v] = values[i];
            edge[v][u] = 1.0 / values[i];
            
            visited[u][v] = visited[v][u] = true;
        }

        for (int k = 0; k < idCnt; k++) {
            for (int i = 0; i < idCnt; i++) {
                for (int j = 0; j < idCnt; j++) {
                    if (!visited[i][j] && visited[i][k] && visited[k][j]) {
                        edge[i][j] = edge[i][k] * edge[k][j];
                        visited[i][j] = true;
                    }
                }
            }
        }

        vector<double> answer(M);
        for (int i = 0; i < M; i++) {
            const string& u = queries[i][0], v = queries[i][1];
            
            if (!id.count(u) || !id.count(v) || !visited[id[u]][id[v]]) {
                answer[i] = -1.0;
                continue;
            }
            
            const double d = edge[id[u]][id[v]];
            answer[i] = d;
        }
        return answer;
    }
};
