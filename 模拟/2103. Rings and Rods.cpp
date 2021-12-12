class Solution {
public:
    int countPoints(string rings) {
        int f[10][3];
        memset(f, 0, sizeof f);
        
        const int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            const char col = rings[i];
            const int idx = rings[i + 1] - '0';
            
            if (col == 'R') f[idx][0] ++;
            else if (col == 'G') f[idx][1] ++;
            else f[idx][2] ++;
        }
        
        
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (f[i][0] > 0 && f[i][1] > 0 && f[i][2] > 0) ans++;
        }
        return ans;
    }
};
