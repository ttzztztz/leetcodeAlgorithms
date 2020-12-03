class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> stk;
        const int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') stk.push_back(i + 1);
            else if (s[i] == ')') {
                const int t = stk.back();
                stk.pop_back();
                reverse(s.begin() + t, s.begin() + i);
            }
        }
        
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == ')') continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};
