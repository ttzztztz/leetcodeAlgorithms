class Solution {
public:
    unordered_map<char, pair<int, int>> map;
    vector<vector<vector<int>>> dp;
    int dist(int prev, int next) {
        pair<int, int> p = map[prev + 'A'], n = map[next + 'A'];
        return abs(p.first - n.first) + abs(p.second - n.second);
    }
    int dfs(const string& word, int index, int left, int right) {
        if (index == word.size()) return 0;
        if (dp[index][left][right] != -1) return dp[index][left][right];
        
        int answer = 9999999;
        // move left
        if (left == 29) {
            answer = min(answer, dfs(word, index + 1, word[index] - 'A', right));
        } else {
            answer = min(answer, dfs(word, index + 1, word[index] - 'A', right) + dist(word[index] - 'A', left));
        }
        // move right
        if (right == 29) {
            answer = min(answer, dfs(word, index + 1, left, word[index] - 'A'));
        } else {
            answer = min(answer, dfs(word, index + 1, left, word[index] - 'A') + dist(word[index] - 'A', right));
        }
        
        return dp[index][left][right] = answer;
    }
    int minimumDistance(string word) {
        for (int i = 0; i < 26; i++) {
            map[i + 'A'] = {i / 6, i % 6};
        }
        dp = vector<vector<vector<int>>>(305, vector<vector<int>>(30, vector<int>(30, -1)));
        
        return dfs(word, 0, 29, 29);
    }
};
