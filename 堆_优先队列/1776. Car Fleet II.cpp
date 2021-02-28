class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        typedef tuple<double, int, int> State;
        priority_queue<State, vector<State>, greater<>> heap;
        const int n = cars.size();
        
        vector<double> ans(n, -1.0);
        vector<int> prev(n, -1);
        
        for (int i = 1; i < n; i++) {
            const int l = i - 1, r = i;
            if (cars[l][1] > cars[r][1]) {
                const double t = 1.0 * (cars[r][0] - cars[l][0]) / (1.0 * (cars[l][1] - cars[r][1]));
                heap.emplace(t, l, r);
            }
            prev[i] = i - 1;
        }
        
        while (!heap.empty()) {
            auto [t, l, r] = heap.top();
            heap.pop();
            
            if (ans[l] != -1.0 || ans[r] != -1.0) continue;
            if (prev[l] != -1 && cars[prev[l]][1] > cars[r][1]) {
                const double t = 1.0 * (cars[r][0] - cars[prev[l]][0]) / (1.0 * (cars[prev[l]][1] - cars[r][1]));
                heap.emplace(t, prev[l], r);
            }
            
            ans[l] = t;
            prev[r] = prev[l];
        }
        return ans;
    }
};
