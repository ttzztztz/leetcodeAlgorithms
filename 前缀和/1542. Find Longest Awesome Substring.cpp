class Solution {
public:
    int longestAwesome(string s) {
        const int mask = (1 << 10) - 1;
        int f[mask + 10];
        memset(f, 0xff, sizeof f);
        
        int sum[10];
        memset(sum, 0, sizeof sum);
        
        int answer = 1;
        f[0] = 0;
        const int N = s.size();
        for (int i = 1; i <= N; i++) {
            const int d = s[i - 1] - '0';
            sum[d]++;
            
            int state = 0;
            for (int k = 0; k <= 9; k++) {
                if (sum[k] % 2 == 1) state |= 1 << k;
            }
            
            if (f[state] != -1) answer = max(answer, i - f[state]);
            for (int k = 0; k <= 9; k++) {
                const int nxt = state ^ (1 << k);
                if (f[nxt] != -1) answer = max(answer, i - f[nxt]);
            }
            
            if (f[state] == -1) f[state] = i;
        }
        return answer;
    }
};
