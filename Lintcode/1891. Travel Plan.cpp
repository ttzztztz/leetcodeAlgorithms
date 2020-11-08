class Solution {
public:
    /**
     * @param arr: the distance between any two cities
     * @return: the minimum distance Alice needs to walk to complete the travel plan
     */
    int travelPlan(vector<vector<int>> &arr) {
        this->arr = arr;
        this->n = arr.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(0, 0);
    }
private:
    vector<vector<int>> arr;
    int n;
    int f[15][(1 << 10) + 5];
    
    int dfs(int u, int state) {
        const int mask = (1 << n) - 1;
        if (state == mask) {
            if (u == 0) return 0;
            else return 0x3f3f3f3f;
        }
        
        int& val = f[u][state];
        if (val != -1) return val;
        int ans = 0x3f3f3f3f;
        for (int k = 0; k < n; k++) {
            if (u == k || (state & (1 << k))) continue;
            ans = min(ans, arr[u][k] + dfs(k, state | (1 << k)));
        }
        return val = ans;
    }
};
