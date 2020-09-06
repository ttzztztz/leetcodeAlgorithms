class Solution {
public:
    bool visited[30], cannotFirst[30];
    int count[30];
    bool dfs(const vector<char>& appearChar, int index, int balance) {
        if (index >= appearChar.size()) return balance == 0;
        
        const int ch = appearChar[index] - 'A';
        for (int i = 0; i <= 9; i++) {
            if (!visited[i] && (i >= 1 || !cannotFirst[ch])) {
                visited[i] = true;
                if (dfs(appearChar, index + 1, balance + i * count[ch])) {
                    return true;
                }
                visited[i] = false;
            }
        }
        
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        memset(visited, 0, sizeof(visited));
        memset(cannotFirst, 0, sizeof(cannotFirst));
        memset(count, 0, sizeof(count));
        
        unordered_set<char> appear;
        for (const string& word : words) {
            for (int i = 0; i < word.size(); i++) {
                if (i == 0) cannotFirst[word[i] - 'A'] = true;
                count[word[i] - 'A'] -= pow(10, word.size() - i - 1);
                appear.insert(word[i]);
            }
        }
        for (int i = 0; i < result.size(); i++) {
            if (i == 0) cannotFirst[result[i] - 'A'] = true;
            count[result[i] - 'A'] += pow(10, result.size() - i - 1);
            appear.insert(result[i]);
        }
        
        vector<char> appearChar;
        for (const char ch : appear) {
            appearChar.push_back(ch);
        }
        return dfs(appearChar, 0, 0);
    }
};
