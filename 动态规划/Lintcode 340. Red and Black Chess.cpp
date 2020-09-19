class Solution {
public:
    /**
     * @param color: the color of each piece
     * @param number: the number of each piece
     * @return: the minimum number of operations
     */
    int RedBlackChess(string &color, vector<int> &number) {
        // write your code here.
        memset(f, 0xff, sizeof f);
        memset(cost, 0, sizeof cost);
        memset(data, 0, sizeof data);
        
        const int n = number.size() / 2;
        R = B = vector<int>(n, 0);
        this->len = color.size();
        
        for (int i = 0; i < number.size(); i++) {
            if (color[i] == 'R') {
                R[number[i] - 1] = i + 1;
            } else { // B
                B[number[i] - 1] = i + 1;
            }
        }
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i < n) {
                    cost[i][j][0] = R[i] - 1 - query(R[i]);
                }
                
                if (j < n) {
                    cost[i][j][1] = B[j] - 1 - query(B[j]);
                    inc(B[j], 1);
                }
                
            }
            
            for (int j = 0; j < n; j++) inc(B[j], -1);
            if (i < n) inc(R[i], 1);
        }
        
        return dfs(0, 0);
    }
private:
    vector<int> R, B;
    int cost[2005][2005][2];
    int f[2005][2005];
    int len;
    int data[6005];
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += data[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void inc(int x, int y) {
        while (x && x <= 6000) {
            data[x] += y;
            x += lowbit(x);
        }
    }
    
    int dfs(int red, int blue) {
        if (red + blue == len) return 0;
        int& val = f[red][blue];
        if (val != -1) return val;
        
        int ans = numeric_limits<int>::max();
        if (red < R.size()) ans = min(ans, cost[red][blue][0] + dfs(red + 1, blue));
        if (blue < B.size()) ans = min(ans, cost[red][blue][1] + dfs(red, blue + 1));
        return val = ans;
    }
};
