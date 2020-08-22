long long f[500][60005];

class Solution {
public:
    /**
     * @param red: the number of red stones
     * @param green: the number of green stones
     * @return: return the ans mod 1e9 + 7
     */
    int twoColorsTower(int red, int green) {
        memset(f, 0xff, sizeof f);
        r = red, g = green;
        this->m = dfs2(0, 0);
        memset(f, 0xff, sizeof f);
        return dfs(0, 0);
    }
private:
    int r, g, m;
    const int mod = 1e9+7;

    long long dfs2(int i, int usedRed) {
        long long& val = f[i][usedRed];
        if (val != -1) return val;
        const int ttl = ((i * i) + i) / 2;
        
        const int usedGreen = ttl - usedRed;
        long long answer = 0;
        if (usedRed + i + 1 <= r) {
            answer = max(answer, 1 + dfs2(i + 1, usedRed + i + 1));
        }
        
        if (usedGreen + i + 1 <= g) {
            answer = max(answer, 1 + dfs2(i + 1, usedRed));
        }
        return val = answer;
    }
    long long dfs(int i, int usedRed) {
        if (i == m) return 1;
        long long& val = f[i][usedRed];
        if (val != -1) return val;
        const int ttl = ((i * i) + i) / 2;
        
        const int usedGreen = ttl - usedRed;
        long long answer = 0;
        
        if (usedRed + i + 1 <= r) {
            answer += dfs(i + 1, usedRed + i + 1);
            answer %= mod;
        }
        
        if (usedGreen + i + 1 <= g) {
            answer += dfs(i + 1, usedRed);
            answer %= mod;
        }
        
        return val = answer;
    }
};
