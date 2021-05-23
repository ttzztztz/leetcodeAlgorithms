class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int n = dist.size();
        // sort(dist.begin(), dist.end(), [&](const auto& lhs, const auto& rhs) -> bool {
        //     return lhs > rhs;
        // });
        int l = 1, r = 100000000;
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            if (solve(dist, mid) <= hour) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        if (solve(dist, l) > hour) return -1;
        else return l;
    }
private:
    double solve(const vector<int>& d, int v) {
        double ans = 0.0;
        for (int i = 0; i < d.size(); i++) {
            const int t = d[i] / v;
            
            if (i == d.size() - 1) {
                ans += (1.0 * d[i]) / (1.0 * v);
            } else {
                if (d[i] % v != 0) ans += t + 1;
                else ans += t;
            }
        }
        
        return ans;
    }
};
