class Solution {
public:
    int digit[15], digitLen, answer[15];
    bool dfs(int i, int isSmall, int last) {
        if (i == 0) {
            return true;
        }
        
        for (int k = 9; k >= 0; k--) {
            if (!isSmall && k > digit[i]) continue;
            if (i != digitLen && k < last) continue;
            
            answer[i] = k;
            if (dfs(i - 1, isSmall || k < digit[i], k)) return true;
        }
        return false;
    }
    int monotoneIncreasingDigits(int N) {
        digitLen = 0;
        int NN = N;
        while (NN) {
            digit[++digitLen] = NN % 10;
            NN /= 10;
        }
        
        memset(answer, 0, sizeof(answer));
        dfs(digitLen, 0, 0);
        int ans = 0;
        while (digitLen >= 0 && answer[digitLen] == 0) digitLen--;
        for (int i = digitLen; i >= 1; i--) {
            ans += answer[i] * pow(10, i - 1);
        }
        return ans;
    }
};
