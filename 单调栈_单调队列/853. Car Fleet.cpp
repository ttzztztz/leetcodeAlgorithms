class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        typedef pair<int, int> PII;
        vector<PII> v;
        const int n = speed.size();
        for (int i = 0; i < n; i++) v.emplace_back(position[i], speed[i]);
        sort(v.begin(), v.end());
        
        vector<double> stk;
        for (auto [pos, sped] : v) {
            const double t = 1.0 * (target - pos) / (1.0 * sped);
            while (!stk.empty() && stk.back() <= t) stk.pop_back();
            stk.push_back(t);
        }
        return stk.size();
    }
};
