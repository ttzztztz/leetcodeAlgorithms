class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> stk = {0};
        const int n = S.size();
        
        for (const char ch : S) {
            if (ch == '(') {
                stk.push_back(0);
            } else { // )
                const int a = stk.back();
                stk.pop_back();
                const int b = stk.back();
                stk.pop_back();
                const int t = b + max(2 * a, 1);
                stk.push_back(t);
            }
        }
        
        return stk.back();
    }
};
