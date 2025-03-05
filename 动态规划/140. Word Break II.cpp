class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string cur;
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        dfs(s, cur, 0);
        return ans;
    }
private:
    vector<string> ans;
    unordered_set<string> dict;
    
    void dfs(const string& s, string& cur, int idx) {
        if (idx >= s.size()) {
            ans.push_back(cur);
            return;
        }

        string tmp;
        for (int j = idx; j < s.size(); j++) {
            tmp += s[j];
            if (dict.count(tmp)) {
                const string prev_cur = cur;
                if (idx != 0) cur += " ";
                cur += tmp;
                dfs(s, cur, j + 1);
                cur = prev_cur;
            }
        }
    }
};