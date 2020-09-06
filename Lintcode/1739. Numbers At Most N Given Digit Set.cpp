class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        digitSet.push_back(0);
        for (const string& s : D) digitSet.push_back(s[0] - '0');
        init(N);
        
        return dfs(digitLen, 0, 1);
    }
private:
    vector<int> digitSet;
    int digit[15];
    int f[15][2][2];
    int digitLen;
    void init(int N) {
        memset(digit, 0, sizeof(digit));
        memset(f, 0xff, sizeof(f));
        digitLen = 0;
        
        while (N) {
            digit[++digitLen] = N % 10;
            N /= 10;
        }
    }
    int dfs(int length, int isSmall, int isZero) {
        if (length == 0) return isZero ? 0 : 1;
        if (f[length][isSmall][isZero] != -1) return f[length][isSmall][isZero];
        
        int answer = 0;
        for (int d : digitSet) {
            if (d == 0 && !isZero) continue;
            if (!isSmall && d > digit[length]) break;
            
            answer += dfs(
                length - 1,
                isSmall || d < digit[length],
                isZero && d == 0
            );
        }
        return f[length][isSmall][isZero] = answer;
    }
};
