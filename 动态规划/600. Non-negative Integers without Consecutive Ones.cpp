class Solution {
public:
    int findIntegers(int n) {
        memset(f, 0xff, sizeof f);
        memset(digit_arr, 0, sizeof digit_arr);
        while (n) {
            digit_arr[++digit_len] = (n & 1);
            n >>= 1;
        }
        
        return dfs(digit_len, 0, 0);
    }
private:
    int f[35][2][2], digit_arr[35], digit_len = 0;
    
    int dfs(int idx, int is_small, int last) {
        if (idx == 0) return 1;
        int& val = f[idx][is_small][last];
        if (val != -1) return val;
        
        int ans = 0;
        for (int d = 0; d <= 1; d++) {
            if (!is_small && d > digit_arr[idx]) continue;
            if (last == 1 && d == 1) continue;
            
            ans += dfs(
                idx - 1,
                is_small || d < digit_arr[idx],
                d
            );
        }
        return val = ans;
    }
};