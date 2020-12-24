class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        typedef tuple<int, int, int> State;
        vector<State> dists;
        const int n = workers.size(), m = bikes.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dists.emplace_back(abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]), i, j);
            }
        }
        
        sort(dists.begin(), dists.end());
        vector<bool> visited_workers(n + 1, false), visited_bikes(m + 1, false);
        vector<int> ans(n);
        for (int i = 0; i < dists.size(); i++) {
            auto [dist, worker, bike] = dists[i];
            if (visited_workers[worker] || visited_bikes[bike]) continue;
            
            visited_workers[worker] = true;
            visited_bikes[bike] = true;
            ans[worker] = bike;
        }
        return ans;
    }
};
