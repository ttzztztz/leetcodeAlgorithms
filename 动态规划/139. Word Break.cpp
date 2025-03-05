class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), -1);
        word_set = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }
private:
    vector<int> memo;
    unordered_set<string> word_set;

    bool dfs(const string& str, int i) {
        if (i >= str.size()) return true;
        if (memo[i] != -1) return memo[i];

        string buf;
        for (int j = i; j < str.size(); j++) {
            buf += str[j];

            if (word_set.count(buf) && dfs(str, j + 1)) return memo[i] = true;
        }
        return memo[i] = false;
    }
};