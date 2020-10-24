class Solution {
public:
    /**
     * @param obstacles: the tracks which obstacles are settled on.
     * @return: return the minimum times to switch the track.
     */
    int trackSwitching(vector<int> &obstacles) {
        // write your code here.
        this->obs = obstacles;
        memset(f, 0xff, sizeof f);
        memset(g, 0, sizeof g);
        
        const int n = obstacles.size();
        for (int i = 0; i < n; i++) g[i][obstacles[i]] = true;
        
        return dfs(0, 2);
    }
private:
    bool g[50005][4];
    int f[50005][4];
    
    vector<int> obs;
    int dfs(int pos, int idx) {
        if (pos == obs.size()) return 0;
        int& val = f[pos][idx];
        if (val != -1) return val;
        
        int ans = 9999999;
        for (int k = 1; k <= 3; k++) {
            if (k == idx && g[pos][idx]) continue;
            
            ans = min(ans, (k != idx) + dfs(pos + 1, k));
        }
        return val = ans;
    }
};
