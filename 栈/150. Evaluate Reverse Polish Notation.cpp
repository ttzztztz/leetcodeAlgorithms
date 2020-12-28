class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        vector<int> stk;
        
        for (const string& token : tokens) {
            if (token == "+") {
                auto [lhs, rhs] = get_operator(stk);
                stk.push_back(lhs + rhs);
            } else if (token == "-") {
                auto [lhs, rhs] = get_operator(stk);
                stk.push_back(lhs - rhs);
            } else if (token == "*") {
                auto [lhs, rhs] = get_operator(stk);
                stk.push_back(lhs * rhs);
            } else if (token == "/") {
                auto [lhs, rhs] = get_operator(stk);
                stk.push_back(lhs / rhs);
            } else { // number
                stk.push_back(stoi(token));
            }
        }
        return stk.back();
    }
private:
    pair<int, int> get_operator(vector<int>& stk) {
        const int rhs = stk.back();
        stk.pop_back();
        const int lhs = stk.back();
        stk.pop_back();
        
        return { lhs, rhs };
    }
};
