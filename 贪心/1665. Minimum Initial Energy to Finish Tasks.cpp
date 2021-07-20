class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        const int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs[1] - lhs[0] > rhs[1] - rhs[0];
        });
        
        int sum = 0;
        for (auto& task : tasks) sum += task[0];
        int ans = sum;

        for (int i = 0, cur = sum; i < n; i++) {
            const auto& task = tasks[i];
            
            if (cur < task[1]) {
                ans += task[1] - cur;
                cur = task[1] - task[0];
            } else {
                cur -= task[0];
            }
        }
        return ans;
    }
};