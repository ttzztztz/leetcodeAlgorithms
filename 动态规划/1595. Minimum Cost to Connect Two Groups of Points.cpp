int f[14][4100];
int pre[14][4100];

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        this->c = cost;
        this->n = cost.size(), this->m = cost[0].size();
        this->m1 = (1 << n) - 1, this->m2 = (1 << m) - 1;
        
        memset(pre, 0, sizeof pre);
        memset(f, 0xff, sizeof f);
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i <= m2; i++) {
                int cur = 0;
                for (int j = 0; j < m; j++) {
                    if (i & (1 << j)) cur += cost[k][j];
                }
                pre[k][i] = cur;
            }
        }
        
        return dfs(0, 0);
    }
private:
    vector<vector<int>> c;
    
    int n, m;
    int m1, m2;
    int dfs(int a, int state2) {
        if (a == n) {
            if (state2 == m2) return 0;
            else return 9999999;
        }
        int& val = f[a][state2];
        if (val != -1) return val;
        
        int ans = 9999999;
        for (int i = 0; i < m; i++) {
            if (state2 & (1 << i)) ans = min(ans, pre[a][1 << i] + dfs(a + 1, state2));
        }
        
        const int sub = (~state2) & m2;
        for (int i = sub; i > 0; i = (i - 1) & sub) {
            ans = min(ans, pre[a][i] + dfs(a + 1, state2 | i));
        }
        
        return val = ans;
    }
    
    int lowbit(int x) {
        return x&(-x);
    }
};
