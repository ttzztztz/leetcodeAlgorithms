class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        const int n = timeSeries.size();
        for (int i = 0, lst = -1; i < n; i++) {
            const int t = timeSeries[i];
            
            ans += duration;
            if (lst >= t) {
                ans -= lst - t + 1;
            }
            lst = t + duration - 1;
        }
        return ans;
    }
};
