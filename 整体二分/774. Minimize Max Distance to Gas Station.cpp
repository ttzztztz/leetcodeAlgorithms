class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        if (stations.empty()) return 0;

        double l = 0.0, r = numeric_limits<double>::min();
        for (int i = 1; i < stations.size(); i++) {
            r = max(r, (double) (stations[i] - stations[i - 1]));
        }
        
        while (abs(r - l) > 1e-6) {
            const double mid = (l + r) / 2.0;
            
            if (solve(stations, mid) <= K) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return l;
    }
private:
    int solve(const vector<int>& stations, double dist) {
        int ans = 0;
        for (int i = 1; i < stations.size(); i++) {
            ans += 1.0 * (stations[i] - stations[i - 1]) / dist;
        }
        return ans;
    }
};
