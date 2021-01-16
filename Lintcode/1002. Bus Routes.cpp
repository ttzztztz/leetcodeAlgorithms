class Solution {
public:
    /**
     * @param routes:  a list of bus routes
     * @param S: start
     * @param T: destination
     * @return: the least number of buses we must take to reach destination
     */
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
        unordered_map<int, vector<int>> point_buses;
        for (int i = 0; i < routes.size(); i++) {
            for (int j : routes[i]) {
                point_buses[j].push_back(i);
            }
        }
        
        unordered_set<int> visited_point, visited_bus;
        deque<int> point_queue = {S};
        int dist = 0;
        while (!point_queue.empty()) {
            const int queue_size = point_queue.size();
            for (int queue_idx = 0; queue_idx < queue_size; queue_idx++) {
                const int point = point_queue.front();
                point_queue.pop_front();
                visited_point.insert(point);
                
                if (point == T) return dist;
                for (int bus : point_buses[point]) {
                    if (visited_bus.count(bus)) continue;
                    visited_bus.insert(bus);

                    for (int next_point : routes[bus]) {
                        if (visited_point.count(next_point)) continue;
                        
                        if (next_point == T) return dist + 1;
                        point_queue.push_back(next_point);
                        visited_point.insert(next_point);
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
