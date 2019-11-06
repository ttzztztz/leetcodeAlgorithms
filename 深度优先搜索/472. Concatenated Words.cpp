class Solution {
public:
    unordered_set<string> stringSet;
    bool dfs(const string& str, int index, int count) {
        const int N = str.size();
        if (index == N && count >= 2) {
            return true;
        }

        for (int i = index; i < N; i++) {
            const string newStr = str.substr(index, i - index + 1);
            if (stringSet.count(newStr) && dfs(str, i + 1, count + 1)) {
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (const string& str : words) {
            stringSet.insert(str);
        }

        vector<string> answer;
        for (const string& str : words) {
            if (dfs(str, 0, 0)) {
                answer.push_back(str);
            }
        }
        return answer;
    }
};