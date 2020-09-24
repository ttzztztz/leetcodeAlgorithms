class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        long long f[105][30]; // s1[i] 生成 (1 << j) 个 s2，需要 s1[i] 开始的长度
        memset(f, 0, sizeof f);
        
        const int l1 = s1.size(), l2 = s2.size();
        for (int i = 0; i < l1; i++) {
            int ptr = i, cnt = 0;
            for (int j = 0; j < l2; j++) {
                bool find = false;
                for (int cur = 0; cur < l1; cur++) {
                    if (s1[ptr] == s2[j]) {
                        ptr = (ptr + 1) % l1;
                        find = true;
                        cnt++;
                        break;
                    }
                    
                    ptr = (ptr + 1) % l1;
                    cnt++;
                }
                
                if (!find) return 0;
            }
            f[i][0] = cnt;
        }
        
       for (int j = 1; j <= 29; j++) {
           for (int i = 0; i < l1; i++) {
               f[i][j] = f[i][j - 1] + f[(i + f[i][j - 1]) % l1][j - 1];
            }
        }

        long long ans = 0;
        for (int i = 0; i < l1; i++) {
            long long ptr = i, cur = i, tmp = 0;
            for (int j = 29; j >= 0; j--) {
                if (cur + f[ptr][j] <= l1 * n1) {
                    cur += f[ptr][j];
                    ptr = (ptr + f[ptr][j]) % l1;
                    tmp |= 1 << j;
                }
            }
            
            ans = max(ans, tmp);
        }
        return ans / n2;
    }
};
