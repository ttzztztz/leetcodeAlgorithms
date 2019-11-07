class Solution {
public:
    int N;
    unordered_map<int, vector<string>> dp;
    vector<string> dfs(const string& s, const unordered_set<string>& wordSet, int index) {
        if (index == N) {
            return vector<string>(1, "");
        }

        if (dp.count(index)) {
            return dp[index];
        }

        vector<string> answer;
        for (int i = index; i < N; i++) {
            const string str = s.substr(index, i - index + 1);
            if (wordSet.count(str)) {
                vector<string> temp = dfs(s, wordSet, i + 1);

                for (const string& t : temp) {
                    if (t == "") {
                        answer.push_back(str);
                    } else {
                        answer.push_back(str + " " + t);
                    }
                }
            }
        }
        return dp[index] = answer;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (const string& word : wordDict) {
            wordSet.insert(word);
        }
        N = s.size();

        return dfs(s, wordSet, 0);
    }
};