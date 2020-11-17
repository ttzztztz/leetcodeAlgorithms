class Solution {
public:
    /**
     * @param n: the rows of matrix
     * @param m: the cols of matrix
     * @param badcomputers: the bad computers 
     * @return: The answer
     */
    int maintenance(int n, int m, vector<Point> &badcomputers) {
        // Write your code here
        typedef pair<int, int> PII;
        vector<PII> pos(n + 1, {-1, -1});

        for (auto& p : badcomputers) {
            if (pos[p.x] == make_pair(-1, -1)) {
                pos[p.x] = make_pair(p.y, p.y);
            } else {
                pos[p.x].first = min(pos[p.x].first, p.y);
                pos[p.x].second = max(pos[p.x].second, p.y);
            }
        }
        
        vector<int> f = {0, 0x3f3f3f3f};
        m--;
        for (int i = 0; i < n; i++) {
            vector<int> g = {0x3f3f3f3f, 0x3f3f3f3f};
            if (pos[i] == make_pair(-1, -1)) {
                if (f[0] < 0x3f3f3f3f) {
                    g[0] = min(g[0], f[0] + 1);
                    g[1] = min(g[1], f[0] + m + 1);
                }
                
                if (f[1] < 0x3f3f3f3f) {
                    g[1] = min(g[1], f[1] + 1);
                    g[0] = min(g[0], f[1] + m + 1);
                }
            } else {
                if (f[0] < 0x3f3f3f3f) {
                    g[0] = min(g[0], f[0] + pos[i].second * 2 + 1);
                    g[1] = min(g[1], f[0] + m + 1);
                }
                
                if (f[1] < 0x3f3f3f3f) {
                    g[1] = min(g[1], f[1] + (m - pos[i].first) * 2 + 1);
                    g[0] = min(g[0], f[1] + m + 1);
                }
            }
            
            f = g;
        }
        
        return min(f[0], f[1]) - 1;
    }
};