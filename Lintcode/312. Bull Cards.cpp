class Solution {
public:
    /**
     * @param n: the number 
     * @param m: the number of cards in hand
     * @return: the number of different types of cards
     */
    int bullCards(int n, int m) {
        // Write your code here.
        memset(f, 0xff, sizeof f);
        this->n = n, this->m = m;
        
        return dfs(0, m);
    }
private:
    const int mod = 1e9+7;
    long long f[1005][1005];
    int n, m;
    
    long long dfs(int idx, int remain) {
        if (idx == n) return (remain == 0) ? 1 : 0;
        if (remain < 0) return 0;
        
        long long& val = f[idx][remain];
        if (val != -1) return val;
        long long answer = 0;
        
        for (int k = 0; k <= 4; k++) {
            answer += dfs(idx + 1, remain - k);
            answer %= mod;
        }
        
        return val = answer;
    }
};
