class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        const int n = cars.size();
        vector<double> ans(n, -1.0);
        
        vector<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            const int pos = cars[i][0], v = cars[i][1];
            
            while (!stk.empty() && (
                cars[stk.back()][1] >= v || 
                (ans[stk.back()] != -1 && calc_time(cars[i], cars[stk.back()]) >= ans[stk.back()])
            )) {
                stk.pop_back();
            }
            
            if (!stk.empty()) ans[i] = calc_time(cars[i], cars[stk.back()]);
            stk.push_back(i);
        }
        return ans;
    }
private:
    double calc_time(const vector<int>& l, const vector<int>& r) {
        return 1.0 * (r[0] - l[0]) / (1.0 * (l[1] - r[1]));
    }
};
