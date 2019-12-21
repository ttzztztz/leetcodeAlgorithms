class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        deque<pair<int, int>> queue;
        unordered_map<int, unordered_set<int>> station;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                if (!station.count(routes[i][j])) {
                    station[routes[i][j]] = unordered_set<int>{};
                }
                station[routes[i][j]].insert(i);
            }
        }
        unordered_set<int> visited;
        unordered_set<int> visitedBus;
        queue.emplace_back(0, S);

        while (!queue.empty()) {
            int ans, sta;
            tie(ans, sta) = queue.front();
            queue.pop_front();

            if (sta == T) {
                return ans;
            }

            if (visited.count(sta)) continue;
            visited.insert(sta);

            for (const int routeId : station[sta]) {
                if (visitedBus.count(routeId)) continue;

                visitedBus.insert(routeId);
                for (int i = 0; i < routes[routeId].size(); i++) {
                    if (routes[routeId][i] == T) {
                        return ans + 1;
                    }

                    if (!visited.count(routes[routeId][i])) {
                        queue.emplace_back(ans + 1, routes[routeId][i]);
                    }
                }
            }

        }
        return -1;
    }
};