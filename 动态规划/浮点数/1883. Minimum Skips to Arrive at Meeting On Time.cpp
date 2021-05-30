class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        this->dist = dist, this->n = dist.size(), this->speed = speed;
        memset(f, 0xff, sizeof f);
        
        const ll target = 1ll * speed * hoursBefore;
        for (int i = 0; i < n; i++) {
            if (dfs(0, i) <= target) return i;
        }
        return -1;
    }
private:
    typedef long long ll;
    ll f[1001][1001];
    vector<int> dist;
    int n, speed;
    
    const ll inf = numeric_limits<ll>::max() / 2;
    
    ll dfs(int i, int skip) {
        if (i == n) return (skip == 0) ? 0 : inf;
        if (skip < 0) return inf;
        
        ll& val = f[i][skip];
        if (val != -1) return val;
        
        ll ans = dfs(i + 1, skip - 1) + dist[i];
        ans = min(ans, 
                  ((dfs(i + 1, skip) + dist[i] - 1) / speed + 1) * speed
                 );
        return val = ans;
    }
};