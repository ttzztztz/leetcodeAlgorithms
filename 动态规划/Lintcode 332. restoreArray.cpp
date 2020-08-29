class Solution {
public:
    /**
     * @param n: the length of the array.
     * @param l: the least limit for element.
     * @param r: the largest limit for element.
     * @return: return the ways to restore the array.
     */
    int restoreArray(int n, int l, int r) {
        memset(s, 0, sizeof s);
        memset(f, 0xff, sizeof f);
        this->n = n;

        init(l, r);
        return dfs(0, 0);
    }
private:
    int n;
    int s[3];
    long long f[100005][3];
    const int mod = 1e9+7;
    
    long long dfs(int i, int j) {
        if (i == n) return (j == 0) ? 1 : 0;
        long long& val = f[i][j];
        if (val != -1) return val;
        
        long long answer = 0;
        for (int k = 0; k < 3; k++) {
            answer += s[k] * dfs(i + 1, (j + k) % 3);
            answer %= mod;
        }
        
        return val = answer;
    }
    void init(int l, int r) {
        while (l <= r && l % 3 != 0) {
            s[l % 3]++;
            l++;
        }
        while (l <= r && r % 3 != 2) {
            s[r % 3]++;
            r--;
        }
        
        if (l < r) {
            const int d = r - l + 1;
            s[0] += d / 3;
            s[1] += d / 3;
            s[2] += d / 3;
        }
    }
};
