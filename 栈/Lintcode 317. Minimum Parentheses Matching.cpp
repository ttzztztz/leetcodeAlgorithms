class Solution {
public:
    /**
     * @param s: The original string
     * @return:  the lexicographical order of the smallest parentheses to match the legal sequence
     */
    string minimumParenthesesMatching(string &s) {
        // write your code here
        const string invalid = "No solution!";
        deque<int> app;
        const int N = s.size();
        for (int i = 0; i < N; i++) if (s[i] == '*') app.push_back(i);
        
        vector<int> stk;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') stk.push_back(i);
            else if (s[i] == ')') {
                if (stk.empty()) {
                    if (app.empty()) return invalid;
                    else {
                        const int idx = app.front();
                        if (idx > i) return invalid;
                        app.pop_front();
                        s[idx] = '(';
                    }
                } else stk.pop_back();
            }
        }
        
        for (int _ = stk.size() - 1; _ >= 0; _--) {
            if (app.empty()) return invalid;
            
            const int idx = app.back();
            app.pop_back();
            
            const int i = stk[_];
            if (idx < i) return invalid;
            else s[idx] = ')';
        }
        
        string answer;
        for (const char ch : s) {
            if (ch != '*') answer.push_back(ch);
        }
        return answer;
    }
};