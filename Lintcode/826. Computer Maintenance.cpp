class Solution {
public:
    /**
     * @param n: the rows of matrix
     * @param m: the cols of matrix
     * @param badcomputers: the bad computers 
     * @return: The answer
     */
    int maintenance(int n, int m, vector<Point> &badcomputers) {
        vector<set<int>> location(n + 1);
        for (const Point& p : badcomputers) {
            location[p.x].insert(p.y);
        }
        
        vector<vector<int>> f(n + 1, vector<int>(2, 999999));
        
        f[0][0] = 0;
        m--;
        
        for (int i = 1; i <= n; i++) {
            if (location[i - 1].empty()) {
                f[i][0] = min(f[i - 1][0], f[i - 1][1] + m) + 1;
                f[i][1] = min(f[i - 1][1], f[i - 1][0] + m) + 1;
            } else {
                const int maxR = *location[i - 1].rbegin();
                const int maxL = m - *location[i - 1].begin();
                
                f[i][0] = min(f[i - 1][0] + 2 * maxR, f[i - 1][1] + m) + 1;
                f[i][1] = min(f[i - 1][0] + m, f[i - 1][1] + 2 * maxL) + 1;
            }
        }
        
        return min(f[n][0], f[n][1]) - 1;
    }
};
