// 数位 dp

class Solution {
public:
    int rotatedDigits(int N) {
        memset(digit, 0, sizeof digit);
        memset(f, 0xff, sizeof f);
        init(N);
        return dfs(digitLen, 0, 0);
    }
private:
    int digit[7], digitLen = 0;
    int f[7][2][2];
    vector<int> ok = {0, 1, 2, 5, 6, 8, 9};
    
    int dfs(int idx, int isSmall, int isValid) {
        if (idx == 0) return isValid ? 1 : 0;
        int& val = f[idx][isSmall][isValid];
        if (val != -1) return val;
        
        int answer = 0;
        for (int d : ok) {
            if (!isSmall && d > digit[idx]) break;
            
            answer += dfs(
                idx - 1,
                isSmall || d < digit[idx],
                isValid || (d == 2 || d == 6 || d == 5 || d == 9)
            );
        }
        return val = answer;
    }
    
    void init(int t) {
        while (t) {
            digit[++digitLen] = t % 10;
            t /= 10;
        }
    }
};