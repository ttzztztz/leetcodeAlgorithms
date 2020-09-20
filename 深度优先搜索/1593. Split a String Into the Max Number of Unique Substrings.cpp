class Solution {
public:
    int maxUniqueSplit(string s) {
        this->s = s;
        this->n = s.size();
        
        return dfs(0);
    }
private:
    unordered_set<string> visited;
    string s;
    int n;
    int dfs(int idx) {
        if (idx == n) return 0;
        string cur;
        int ans = 0;
        for (int k = idx; k < n; k++) {
            cur += s[k];
            
            if (!visited.count(cur)) {
                visited.insert(cur);
                ans = max(ans, 1 + dfs(k + 1));
                visited.erase(cur);
            }
        }
        return ans;
    }
};
