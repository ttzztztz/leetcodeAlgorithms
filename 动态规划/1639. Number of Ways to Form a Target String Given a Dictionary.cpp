typedef long long ll;
ll f[1005][1005];
int g[256][1005];

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        this->words = words, this->target = target;
        
        memset(f, 0xff, sizeof f);
        memset(g, 0, sizeof g);
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                g[words[i][j]][j]++;
            }
        }
        
        return dfs(0, 0);
    }
private:
    vector<string> words;
    string target;
    const int mod = 1e9+7;
    
    ll dfs(int i, int j) {
        if (i == target.size()) return 1;
        if (j >= words[0].size()) return 0;
        
        ll& val = f[i][j];
        if (val != -1) return val;
        
        ll ans = 0;
        ans = (ans + dfs(i, j + 1)) % mod;
        ans = (ans + dfs(i + 1, j + 1) * g[target[i]][j]) % mod;
        return val = ans;
    }
};
