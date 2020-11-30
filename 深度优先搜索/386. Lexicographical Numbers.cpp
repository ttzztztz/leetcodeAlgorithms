class Solution {
public:
    vector<int> lexicalOrder(int n) {
        this->n = n;
        for (int i = 1; i <= 9; i++) dfs(i);
        return ans;
    }
private:
    vector<int> ans;
    int n;
    
    void dfs(int u) {
        if (u > n) return;
        ans.push_back(u);
        
        for (int i = 0; i <= 9; i++) {
            dfs(u * 10 + i);
        }
    }
};
