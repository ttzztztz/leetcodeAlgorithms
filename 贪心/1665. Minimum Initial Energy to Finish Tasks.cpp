class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int l = 1, r = 0;
        const int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[0] - $1[1] < $2[0] - $2[1];
        });
        for (int i = 0; i < n; i++) r += tasks[i][1];
        
        while (l <= r) {
            const int m = (l + r) >> 1;
            if (solve(tasks, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
private:
    bool solve(const vector<vector<int>>& tasks, int current) {
        for (int i = 0; i < tasks.size(); i++) {
            if (current >= tasks[i][1]) {
                current -= tasks[i][0];
            } else return false;
        }
        return true;
    }
};
