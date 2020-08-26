class Solution {
public:
    /**
     * @param str: a string S
     * @return: the number of different non-empty palindromic subsequences in S
     */
    int countPalindSubseq(string &str) {
        memset(f, 0xff, sizeof f);
        this->str = str;
        n = str.size();
        return dfs(0, n - 1);
    }
private:
    long long f[1005][1005];
    const int mod = 1e9+7;
    string str;
    int n;
    
    long long dfs(int l, int r) {
        if (l == r) return 1;
        if (l > r) return 0;
        
        long long& val = f[l][r];
        if (val != -1) return val;
        
        long long answer = 0;
        if (str[l] == str[r]) {
            int a = l + 1, b = r - 1;
            while (a <= b && str[a] != str[l]) a++;
            while (a <= b && str[b] != str[l]) b--;
            
            if (a > b) {
                answer = 2ll * dfs(l + 1, r - 1) + 2;
                answer %= mod;
            } else if (a == b) {
                answer = 2ll * dfs(l + 1, r - 1) + 1;
                answer %= mod;
            } else {
                answer = 2ll * dfs(l + 1, r - 1) - dfs(a + 1, b - 1);
                answer %= mod;
                answer += mod;
                answer %= mod;
            }
        } else {
            answer = dfs(l, r - 1) + dfs(l + 1, r) - dfs(l + 1, r - 1);
            answer %= mod;
            answer += mod;
            answer %= mod;
        }
        return val = answer;
    }
};
