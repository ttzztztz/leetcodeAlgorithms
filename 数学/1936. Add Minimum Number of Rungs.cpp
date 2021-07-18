class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0;
        const int n = rungs.size();
        for (int last = 0, i = 0; i < n; i++) {
            const int d = (rungs[i] - last);
            ans += d / dist;
            if (d % dist == 0) ans--;
            
            last = rungs[i];
        }
        return ans;
    }
};