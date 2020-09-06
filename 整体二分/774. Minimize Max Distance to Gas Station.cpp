class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    int solve(const vector<int> &stations, const double dist) {
        int answer = 0;
        const int N = stations.size();
        for (int i = 1; i < N; i++) {
            answer += ceil((stations[i] - stations[i - 1]) / dist) - 1;
        }
        return answer;
    }
    double minmaxGasDist(vector<int> &stations, int k) {
        const int N = stations.size();
        double left = 0.0, right = stations[N - 1] - stations[0];
        while (right - left >= 1e-6) {
            const double mid = (left + right) * 0.5;
            if (solve(stations, mid) <= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
