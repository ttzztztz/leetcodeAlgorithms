class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        const int n = S.size();
        const int m = indexes.size();
        
        unordered_map<int, pair<int, int>> replace;
        for (int i = 0; i < m; i++) {
            if (cmp(S, indexes[i], sources[i])) {
                replace[indexes[i]] = { i, (int) sources[i].size() };
            }
        }
        
        string ans;
        for (int i = 0; i < n; i++) {
            if (replace.count(i)) {
                auto [idx, len] = replace[i];
                ans += targets[idx];
                i += len - 1;
            } else {
                ans += S[i];
            }
        }
        return ans;
    }
private:
    bool cmp(const string& str, int start, const string& target) {
        const int n = str.size();
        if (n - start + 1 < target.size()) return false;
        for (int i = 0; i < target.size(); i++) {
            if (str[start + i] != target[i]) return false;
        }
        return true;
    }
};