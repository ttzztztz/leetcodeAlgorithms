class Solution {
public:
    vector<int> beautifulArray(int n) {
        return dfs(n);
    }
private:
    unordered_map<int, vector<int>> memo;
    
    vector<int> dfs(int n) {
        if (n == 0) return {};
        else if (n == 1) return { 1 };
        
        if (memo.count(n)) return memo[n];
        vector<int> ans(n);
        int ptr = 0;
        for (int i : dfs((n + 1) / 2)) ans[ptr++] = 2 * i - 1;
        for (int i : dfs(n / 2)) ans[ptr++] = 2 * i;
        return memo[n] = ans;
    }
};