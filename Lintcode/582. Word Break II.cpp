class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<vector<string>> dp;
    vector<bool> stateValid;
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        dp = vector<vector<string>>(s.size(), vector<string>{});
        stateValid = vector<bool>(s.size(), false);
        
        vector<string> answer = dfs(s, wordDict, 0);
        for (string& str : answer) str.pop_back();
        return answer;
    }
    vector<string> dfs(const string &s, const unordered_set<string> &wordDict, int u) {
        if (u == s.size()) return vector<string>{""};
        if (stateValid[u]) return dp[u];
        
        vector<string> answer;
        string cur;
        for (int i = u; i < s.size(); i++) {
            cur += s[i];
            if (!wordDict.count(cur)) continue;
            
            vector<string> tmp = dfs(s, wordDict, i + 1);
            for (const string& s : tmp) answer.emplace_back(cur + " " + s);
        }
        stateValid[u] = true;
        return dp[u] = answer;
    }
};
