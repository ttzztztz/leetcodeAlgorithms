class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return ans;
    }
private:
    vector<string> ans;
    void dfs(string& str, int idx) {
        if (idx == str.size()) {
            ans.push_back(str);
            return;
        }
        
        if (str[idx] >= 'a' && str[idx] <= 'z') {
            const int offset = str[idx] - 'a';
            dfs(str, idx + 1);
            
            str[idx] = 'A' + offset;
            dfs(str, idx + 1);
            str[idx] = 'a' + offset;
        } else if (str[idx] >= 'A' && str[idx] <= 'Z') {
            const int offset = str[idx] - 'A';
            dfs(str, idx + 1);
            
            str[idx] = 'a' + offset;
            dfs(str, idx + 1);
            str[idx] = 'A' + offset;
        } else {
            dfs(str, idx + 1);
        }
    }
};
