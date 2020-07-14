class Solution {
public:
    int fib(int N) {
        memset(memo, 0xff, sizeof memo);
        return dfs(N);
    }
private:
    int memo[35];
    int dfs(int N) {
        if (N == 0) return 0;
        else if (N == 1) return 1;
        
        int& val = memo[N];
        if (val != -1) return val;
        
        return val = dfs(N - 1) + dfs(N - 2);
    }
};