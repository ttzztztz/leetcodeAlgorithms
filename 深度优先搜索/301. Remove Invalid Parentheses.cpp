class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, 0);
        return vector<string>(answer.begin(), answer.end());
    }
private:
    unordered_set<string> answer;
    vector<char> stk;
    
    vector<char> curStk;
    int removeCnt = 9999999;
    
    void dfs(const string& s, int i, int remove) {
        if (remove > removeCnt) return;
        if (i == s.size()) {
            if (!curStk.empty()) return;
            
            if (remove < removeCnt) {
                removeCnt = remove;
                answer = {string(stk.begin(), stk.end())};
            } else if (remove == removeCnt) {
                answer.insert(string(stk.begin(), stk.end()));
            }
            return;
        }
        
        if (s[i] != '(' && s[i] != ')') {
            stk.push_back(s[i]);
            dfs(s, i + 1, remove);
            stk.pop_back();
            return;
        }
        
        if (s[i] == '(') {
            dfs(s, i + 1, remove + 1);
            
            stk.push_back(s[i]);
            curStk.push_back('(');
            dfs(s, i + 1, remove);
            curStk.pop_back();
            stk.pop_back();
        } else if (s[i] == ')') {
            dfs(s, i + 1, remove + 1);
            
            if (!curStk.empty()) {
                stk.push_back(s[i]);
                curStk.pop_back();
                dfs(s, i + 1, remove);
                curStk.push_back('(');
                stk.pop_back();
            }
        }
    }
};
