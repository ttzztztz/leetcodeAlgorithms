class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        if (seats.empty()) return 0;
        const int n = seats.size(), m = seats[0].size();
        vector<int> f((1 << m) + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            vector<int> g((1 << m) + 1, 0);
            for (int last = 0; last < (1 << m); last++) {
                int ans = 0;
                for (int next = 0; next < (1 << m); next++) {
                    bool valid = true;
                    for (int j = 0; j < m; j++) {
                        if (!(next & (1 << j))) continue;

                        if (seats[i][j] == '#') {
                            valid = false;
                            break;
                        }

                        if ((j - 1 >= 0 && (next & (1 << (j - 1))))
                            || (j - 1 >= 0 && (last & (1 << (j - 1))))
                            || (j + 1 < m && (next & (1 << (j + 1))))
                            || (j + 1 < m && (last & (1 << (j + 1))))
                        ) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    const int cost = __builtin_popcount(next);
                    ans = max(ans, f[next] + cost);
                }
                g[last] = ans;
            }
            f = g;
        }
        
        return f[0];
    }
};