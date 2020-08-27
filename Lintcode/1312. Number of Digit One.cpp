class Solution {
public:
    /**
     * @param n: an integer 
     * @return: the total number of digit 1
     */
    int countDigitOne(int n) {
        // write your code here
        memset(f, 0xff, sizeof f);
        memset(number, 0, sizeof number);
        
        int t = n;
        while (t) {
            number[++digitLen] = t % 10;
            t /= 10;
        }
        
        return dfs(digitLen, 0, 0);
    }
private:
    int number[15];
    int digitLen = 0;
    
    int f[15][2][15];
    int dfs(int digit, int isSmall, int cnt) {
        if (digit == 0) return cnt;
        int& val = f[digit][isSmall][cnt];
        if (val != -1) return val;
        
        int answer = 0;
        for (int k = 0; k <= 9; k++) {
            if (!isSmall && k > number[digit]) break;
            
            answer += dfs(
                digit - 1,
                isSmall || k < number[digit],
                cnt + (k == 1));
        }
        return val = answer;
    }
};
