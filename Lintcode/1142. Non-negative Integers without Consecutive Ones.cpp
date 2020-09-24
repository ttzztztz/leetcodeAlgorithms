class Solution {
public:
    /**
     * @param num: an integer
     * @return: the number of non-negative integers less than or equal to n
     */
    int findIntegers(int num) {
        init(num);
        return dfs(digitLen, 0, 0);
    }
private:
    int f[35][2][2];
    int digit[35];
    int digitLen = 0;
    
    void init(int num) {
        memset(f, 0xff, sizeof f);
        memset(digit, 0, sizeof digit);
        
        while (num) {
            digit[++digitLen] = num & 1;
            num >>= 1;
        }
    }
    
    int dfs(int idx, int lst, int isSmall) {
        if (idx == 0) return 1;
        int& val = f[idx][lst][isSmall];
        if (val != -1) return val;
        
        int ans = 0;
        for (int d = 0; d <= 1; d++) {
            if (!isSmall && d > digit[idx]) break;
            if (lst == 1 && d == 1) continue;
            
            ans += dfs(
                idx - 1,
                d,
                isSmall || (d < digit[idx])
            );
        }
        return val = ans;
    }
};
