class Solution {
public:
    /**
     * @param N: The number of buses
     * @param route: The route of buses
     * @param A: Start bus station
     * @param B: End bus station
     * @return: Return the minimum transfer number
     */
    int getMinTransferNumber(int N, vector<vector<int>> &route, int A, int B) {
        unordered_set<int> busVisited, placeVisited;
        unordered_map<int, vector<int>> placeHaveBus;
        for (int i = 0; i < route.size(); i++) {
            for (int place : route[i]) placeHaveBus[place].push_back(i);
        }
        
        int cur = 0;
        deque<int> queue;
        queue.push_back(A);
        while (!queue.empty()) {
            const int cnt = queue.size();
            
            for (int _ = 0; _ < cnt; _++) {
                int u = queue.front();
                queue.pop_front();
                if (u == B) return cur;
                placeVisited.insert(u);
                
                for (int v : placeHaveBus[u]) {
                    if (busVisited.count(v)) continue;
                    busVisited.insert(v);
                    for (int p : route[v]) {
                        if (placeVisited.count(p)) continue;
                        placeVisited.insert(p);
                        if (p == B) return cur + 1;
                        queue.push_back(p);
                    }
                }
            }
            cur++;
        }
        
        return -1;
    }
};
