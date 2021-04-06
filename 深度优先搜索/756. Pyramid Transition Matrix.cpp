class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& allow : allowed) {
            all[allow.substr(0, 2)].push_back(allow[2]);
        }
        return dfs(bottom);
    }
private:
    unordered_map<string, vector<char>> all;
    bool dfs(const string& str) {
        if (str.size() == 1) return true;

        for (const string& nxt : all_possibilities(str, 0)) {
            if (dfs(nxt)) return true;
        }
        return false;
    }
    
    vector<string> all_possibilities(const string& cur, int idx) {
        if (idx + 1 == cur.size()) return {""};
        vector<string> ans;
        string t = string{cur[idx], cur[idx + 1]};
        for (char c : all[t]) {
            for (auto& s : all_possibilities(cur, idx + 1)) {
                ans.push_back(string{c} + s);
            }
        }
        return ans;
    }
};