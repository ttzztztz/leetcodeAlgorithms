class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;

        vector<int> ans;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                const int rhs = ans.back();
                ans.pop_back();
                const int lhs = ans.back();
                ans.pop_back();

                int cur = 0;
                if (token == "+") cur = lhs + rhs;
                else if (token == "-") cur = lhs - rhs;
                else if (token == "*") cur = lhs * rhs;
                else if (token == "/") cur = lhs / rhs;
                ans.push_back(cur);
            } else {
                ans.push_back(stoi(token));
            }
        }
        return ans.back();
    }
};