class Solution {
public:
    /**
     * @param target: the distance of src and the dst 
     * @param startFuel: the init fuel
     * @param stations: station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.
     * @return: the minimun number 
     */
    int minimumNumberofRefuelingStops(int target, int startFuel, vector<vector<int>> &stations) {
        const int N = stations.size();
        vector<vector<long long>> f(N + 2, vector<long long>(N + 5, -999999999));
        
        f[0][0] = startFuel;
        int last = 0;
        for (int i = 1; i <= N; i++) {
            const vector<int>& station = stations[i - 1];
            const int d = station[0] - last;
            
            for (int j = 0; j <= N; j++) {
                if (f[i - 1][j] >= d) {
                    f[i][j] =  max(f[i][j], f[i - 1][j] - d);
                }
                if (j >= 1 && f[i - 1][j - 1] >= d) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + station[1] - d);
                }
            }
            
            last = station[0];
        }
        
        const int d = target - (N >= 1 ? stations[N - 1][0] : 0);
        for (int i = 0; i <= N; i++) {
            if (f[N][i] >= d) return i;
        }
        return -1;
    }
};
