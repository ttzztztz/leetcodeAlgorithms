class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        memset(m, 0xff, sizeof m);
        
        this->d = d;
        this->f = f;
        this->t = target;
        
        return dfs(0, 0);
    }
private:
    int d, f, t;
    long long m[35][1005];
    const int mod = 1e9+7;
    
    long long dfs(int di, int cur) {
        if (cur > t) return 0;
        if (di == d) return cur == t ? 1 : 0;
        
        long long& val = m[di][cur];
        if (val != -1) return val;
        
        long long answer = 0;
        for (int k = 1; k <= f; k++) {
            answer += dfs(di + 1, cur + k);
            answer %= mod;
        }
        return val = answer;
    }
};