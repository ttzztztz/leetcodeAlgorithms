class Solution {
public:
    vector<string> answer;
    unordered_map<string, int> nameToId;
    unordered_map<int, string> idToName;
    vector<vector<int>> graph;

    void dfs(int u) {
        while (graph[u].size() > 0) {
            const int v = graph[u].back();
            graph[u].pop_back();
            dfs(v);
        }

        answer.push_back(idToName[u]);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const int N = tickets.size();

        set<string> stations;
        for (const vector<string>& ticket : tickets) {
            stations.insert(ticket[0]), stations.insert(ticket[1]);
        }
        graph = vector<vector<int>>(stations.size(), vector<int>{});
        int index = 0;
        for (const string& station : stations) {
            nameToId[station] = index;
            idToName[index] = station;

            index++;
        }
        for (const vector<string>& ticket : tickets) {
            graph[nameToId[ticket[0]]].push_back(nameToId[ticket[1]]);
        }

        for (vector<int>& v : graph) {
            sort(v.begin(), v.end(), greater<>());
        }
        dfs(nameToId["JFK"]);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};