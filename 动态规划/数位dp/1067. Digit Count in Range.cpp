class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return solve(high, d) - solve(low - 1, d);
    }
private:
    int f[10][2][10][2];
    int digit_arr[10];
    int digit_len, digit;
    int solve(int n, int d) {
        memset(digit_arr, 0, sizeof digit_arr);
        memset(f, 0xff, sizeof f);
        
        this->digit_len = 0;
        this->digit = d;
        
        while (n) {
            digit_arr[++digit_len] = n % 10;
            n /= 10;
        }
        
        return dfs(digit_len, 0, 0, 1);
    }

    int dfs(int i, int is_small, int cnt, int is_zero) {
        if (i == 0) return cnt;
        int& val = f[i][is_small][cnt][is_zero];
        if (val != -1) return val;
        
        int ans = 0;
        for (int d = 0; d <= 9; d++) {
            if (!is_small && d > digit_arr[i]) break;
            
            int delta = (d == digit) ? 1 : 0;
            if (digit == 0) {
                delta = d == digit && !is_zero;
            }
            
            ans += dfs(
                i - 1,
                is_small || d < digit_arr[i],
                cnt + delta,
                is_zero && d == 0
            );
        }
        return val = ans;
    }
};
