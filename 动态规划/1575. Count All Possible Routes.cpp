class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(f, 0xff, sizeof f);
        this->s = start;
        this->e = finish;
        this->loc = locations;
        this->n = locations.size();
        
        return dfs(start, fuel);
    }
private:
    long long f[105][205];
    vector<int> loc;
    int s, e, n;
    const int mod = 1e9+7;
    
    long long dfs(int u, int fuel) {
        if (fuel < 0) return 0;
        
        long long& val = f[u][fuel];
        if (val != -1) return val;
        
        long long answer = (u == e);
        for (int i = 0; i < n; i++) {
            if (i == u) continue;
            
            const int d = abs(loc[i] - loc[u]);
            if (fuel >= d) answer = (answer + dfs(i, fuel - d)) % mod;
        }
        return val = answer;
    }
};
