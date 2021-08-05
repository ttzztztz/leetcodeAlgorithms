class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        this->piles = piles;
        const int n = piles.size();
        
        const int sum = accumulate(piles.begin(), piles.end(), 0);
        f = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        
        const int u = dfs(0, n - 1);
        return u > sum - u;
    }
private:
    vector<vector<int>> f;
    vector<int> piles;
    
    int dfs(int l, int r) {
        if (l == r) return 0;
        int& val = f[l][r];
        if (val != -1) return val;
        
        int ans = 0;
        const int u = (r - l + 1) % 2;
        if (u % 2 == 0) { // Alice
            ans = max(piles[l] + dfs(l + 1, r), piles[r] + dfs(l, r - 1));
        } else { // Bob
            ans = min(dfs(l + 1, r), dfs(l, r - 1));
        }
        return val = ans;
    }
};
