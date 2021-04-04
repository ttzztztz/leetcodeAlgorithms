class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        a = vector<int>(batchSize, 0);
        bs = batchSize;
        for (int i : groups) {
            a[i % batchSize]++;
        }
        
        return dfs(0);
    }
private:
    vector<int> a;
    map<vector<int>, int> f;
    int bs;
    
    int dfs(int rest) {
        if (f.count(a)) return f[a];

        int ans = 0;
        for (int i = 0; i < bs; i++) {
            if (a[i] == 0 || (a[rest] > 0 && i != rest)) continue;
            a[i]--;
            ans = max(ans, (rest == 0) + dfs((bs + rest - i) % bs));
            a[i]++;
        }
        return f[a] = ans;
    }
};