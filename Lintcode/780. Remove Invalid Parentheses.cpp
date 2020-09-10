class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(string &s) {
        this->s = s;
        this->n = s.size();
        dfs(0, 0);
        return vector<string>(answer.begin(), answer.end());
    }
private:
    string s;
    int n;
    unordered_set<string> answer;
    int ansCnt = 999999;
    
    vector<char> stk, symStk;
    void dfs(int idx, int cnt) {
        if (cnt > ansCnt) return;
        if (idx == n) {
            if (!symStk.empty()) return;
            if (cnt < ansCnt) {
                ansCnt = cnt;
                answer = {string(stk.begin(), stk.end())};
            } else if (cnt == ansCnt) {
                answer.insert(string(stk.begin(), stk.end()));
            }
            return;
        }
        
        if (s[idx] == '(') {
            dfs(idx + 1, cnt + 1);
            
            stk.push_back(s[idx]);
            symStk.push_back(s[idx]);
            dfs(idx + 1, cnt);
            stk.pop_back();
            symStk.pop_back();
        } else if (s[idx] == ')') {
            dfs(idx + 1, cnt + 1);
            
            if (!symStk.empty()) {
                stk.push_back(s[idx]);
                symStk.pop_back();
                dfs(idx + 1, cnt);
                symStk.push_back(idx);
                stk.pop_back();
            }
        } else {
            stk.push_back(s[idx]);
            dfs(idx + 1, cnt);
            stk.pop_back();
        }
    }
};