class Solution {
public:
    vector<int> dp;
    int dfs(const string& s, const unordered_set<string>& wordDict, int start) {
        if (start == s.size()) {
            return dp[start] = 1;
        }
        if (dp[start] != -1) {
            return dp[start];
        }

        for (int len = 1; start + len <= s.size(); len++) {
            if (wordDict.count(s.substr(start, len)) && dfs(s, wordDict, start + len)) {
                return dp[start] = 1;
            }
        }

        return dp[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size() + 5, -1);
        unordered_set<string> wordDictSet;
        for (int i = 0; i < wordDict.size(); i++) {
            wordDictSet.insert(wordDict[i]);
        }
        return dfs(s, wordDictSet, 0) == 1;
    }
};