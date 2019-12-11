class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<double>> edge(30, vector<double>(30, 0.0));
        vector<vector<bool>> used(30, vector<bool>(30, false));

        unordered_map<string, int> id;
        int id_count = 0;
        for (int i = 0; i < equations.size(); i++) {
            if (!id.count(equations[i][0])) {
                id[equations[i][0]] = id_count++;
            }
            if (!id.count(equations[i][1])) {
                id[equations[i][1]] = id_count++;
            }

            const int u = id[equations[i][0]], v = id[equations[i][1]];
            edge[u][v] = values[i], edge[v][u] = 1.0 / values[i];
            used[u][v] = used[v][u] = true;
        }

        for (int k = 0; k < id_count; k++) {
            for (int u = 0; u < id_count; u++) {
                for (int v = 0; v < id_count; v++) {
                    if (!used[u][v] && used[u][k] && used[k][v]) {
                        used[u][v] = true;
                        edge[u][v] = edge[u][k] * edge[k][v];
                    }
                }
            }
        }

        vector<double> answer;
        for (const vector<string>& query : queries) {
            if (!id.count(query[0]) || !id.count(query[1])) {
                answer.push_back(-1.0);
                continue;
            }

            const int u = id[query[0]], v = id[query[1]];
            if (!used[u][v]) {
                answer.push_back(-1.0);
                continue;
            }

            answer.push_back(edge[u][v]);
        }
        return answer;
    }
};