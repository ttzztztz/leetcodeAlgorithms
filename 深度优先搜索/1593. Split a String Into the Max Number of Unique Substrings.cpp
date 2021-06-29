class Solution {
public:
    int maxUniqueSplit(string s) {
        this->s = s;
        return dfs(0);
    }
private:
    string s;
    unordered_set<string> visited;
    
    int dfs(int idx) {
        if (idx == s.size()) return 0;
        string cur;
        int ans = 0;
        for (int i = idx; i < s.size(); i++) {
            cur += s[i];
            if (!visited.count(cur)) {
                visited.insert(cur);
                ans = max(ans, 1 + dfs(i + 1));
                visited.erase(cur);
            }
        }
        return ans;
    }
};