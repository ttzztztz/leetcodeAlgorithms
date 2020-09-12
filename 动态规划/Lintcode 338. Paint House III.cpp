class Solution {
public:
    /**
     * @param costs: costs of paint ith house into color j
     * @param t: maximum length of street
     * @return: minimum costs of painting all houses
     */
    int paintHouseIII(vector<vector<int>> &costs, int t) {
        // Write your code here.
        this->costs = costs;
        this->t = t;
        this->n = costs.size(), this->k = costs[0].size();
        memset(f, 0xff, sizeof f);
        
        return dfs(0, 101, t);
    }
private:
    vector<vector<int>> costs;
    int n, k;
    int t;
    int f[105][105][15];
    
    int dfs(int i, int last, int street) {
        if (i == n) return 0;
        int& val = f[i][last][street];
        if (val != -1) return val;
        
        int answer = 99999999;
        if (i >= 1 && street > 0 && street < t) {
            answer = min(answer, costs[i][last] + dfs(i + 1, last, street - 1));
            
            for (int c = 0; c < k; c++) {
                answer = min(answer, costs[i][c] + dfs(i + 1, c, 0));
            }
        }
        
        if (i == 0 && street > 0) {
            for (int c = 0; c < k; c++) {
                answer = min(answer, costs[i][c] + dfs(i + 1, c, street - 1));
            }
        }
        
        if (street == 0 || street == t) {
            for (int c = 0; c < k; c++) {
                if (c == last) continue;
                answer = min(answer, costs[i][c] + dfs(i + 1, c, street));
            }
        }
        
        if (street == t) {
            for (int c = 0; c < k; c++) {
                if (c == last) continue;
                answer = min(answer, costs[i][c] + dfs(i + 1, c, t - 1));
            }
        }
        
        return val = answer;
    }
};
