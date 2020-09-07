class Solution {
public:
    /**
     * @param heights: the heights of buildings.
     * @param k: the vision.
     * @param x: the energy to spend of the first action.
     * @param y: the energy to spend of the second action.
     * @return: the minimal energy to spend.
     */
    long long shuttleInBuildings(vector<int> &heights, int k, int x, int y) {
        // write your code here.
        this->h = heights;
        this->x = x;
        this->y = y;
        this->n = heights.size();
        this->k = k;
        
        memset(f, 0xff, sizeof f);
        vector<int> stk, ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.back()] <= heights[i]) stk.pop_back();
            if (!stk.empty()) ans[i] = stk.back();
            stk.push_back(i);
        }
        
        this->sel = ans;
        return dfs(0);
    }
private:
    long long f[100005];
    int x, y, n, k;
    vector<int> h, sel;
    
    long long dfs(int u) {
        if (u >= n) return 999999999;
        if (u == n - 1) return 0;
        long long& val = f[u];
        if (val != -1) return val;
        long long answer = y + min(dfs(u + 1), dfs(u + 2));
        if (sel[u] != -1 && sel[u] - u <= k) answer = min(answer, x + dfs(sel[u]));
        return val = answer;
    }
};
