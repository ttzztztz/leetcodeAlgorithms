class Solution {
public:
    bool isValid(string s) {
        const int N = s.size();
        vector<char> stk;
        for (int i = 0; i < N; i++) {
            const char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push_back(ch);
            } else if (ch == ')') {
                if (stk.empty() || stk.back() != '(') return false;
                stk.pop_back();
            } else if (ch == ']') {
                if (stk.empty() || stk.back() != '[') return false;
                stk.pop_back();
            } else if (ch == '}') {
                if (stk.empty() || stk.back() != '{') return false;
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};