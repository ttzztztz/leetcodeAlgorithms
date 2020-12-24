class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        workers_ = workers, bikes_ = bikes;
        memo_ = vector<vector<int>>(workers.size() + 1, vector<int>((1 << bikes.size()) + 1, -1));
        
        return dfs(0, 0);
    }
private:
    vector<vector<int>> memo_;
    vector<vector<int>> workers_, bikes_;
    
    int dfs(int worker, int bike_state) {
        if (worker == workers_.size()) return 0;
        int& val = memo_[worker][bike_state];
        if (val != -1) return val;
        
        int ans = numeric_limits<int>::max();
        for (int j = 0; j < bikes_.size(); j++) {
            if (bike_state & (1 << j)) continue;
            const int cost = abs(workers_[worker][0] - bikes_[j][0]) + abs(workers_[worker][1] - bikes_[j][1]);
            ans = min(ans, cost + dfs(worker + 1, bike_state | (1 << j)));
        }
        return val = ans;
    }
};
