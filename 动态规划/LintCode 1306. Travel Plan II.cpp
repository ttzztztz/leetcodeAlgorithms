class Solution {
public:
    /**
     * @param arr: the distance between any two cities
     * @return: the minimum distance Alice needs to walk to complete the travel plan
     */
    int travelPlanII(vector<vector<int>> &arr) {
        n = arr.size();
        memset(f, 0xff, sizeof f);
        this->arr = arr;
        
        return dfs(0, 0);
    }
private:
    int f[35000][20];
    int n;
    vector<vector<int>> arr;
    
    int dfs(int state, int cur) {
        if (state == (1 << n) - 1) {
            return cur == 0 ? 0 : 9999999;
        }
        
        int& val = f[state][cur];
        if (val != -1) return val;
        
        int answer = 9999999;
        for (int v = 0; v < n; v++) {
            if (v != cur && (state & (1 << v)) == 0) {
                answer = min(answer, arr[cur][v] + dfs(state | 1 << v, v));
            }
        }
        return val = answer;
    }
};
