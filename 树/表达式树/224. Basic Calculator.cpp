class Solution {
public:
    int calculate(string s) {
        tokens = tokenize(s);
        processed_token = process_token(tokens);
        post_expr = convert_post(processed_token);

        ptr = post_expr.size() - 1;
        return calc();
    }
private:
    int ptr = 0;
    vector<string> tokens, post_expr, processed_token;

    unordered_map<string, int> prior = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };
    unordered_set<string> special_tokens = {
        "+", "-", "*", "/", "("
    };

    vector<string> tokenize(const string& s) {
        vector<string> ans;
        const int n = s.size();
        string tmp;
        for (int i = 0; i < n; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                tmp += s[i];
            } else {
                if (!tmp.empty()) ans.push_back(tmp);
                tmp.clear();
                
                if (s[i] != ' ') {
                    ans.push_back(string{s[i]});
                }
            }
        }
        
        if (!tmp.empty()) ans.push_back(tmp);
        return ans;
    }
    
    vector<string> process_token(vector<string> s) {
        vector<string> ans;
        for (int i = 0; i < s.size(); i++) {
            ans.push_back(s[i]);
            if (
                (i == 0 && prior.count(s[i])) || 
                (i + 1 < s.size() && special_tokens.count(s[i]) && prior.count(s[i + 1]))
            ) {
                ans.push_back("0");
            }
        }
        return ans;
    }
    
    vector<string> convert_post(const vector<string>& s) {
        vector<string> ans;
        
        vector<string> stk;
        for (auto& t : s) {
            if (t == "(") {
                stk.push_back(t);
            } else if (t == ")") {
                while (stk.back() != "(") {
                    ans.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
            } else if (prior.count(t)) {
                while (!stk.empty() && stk.back() != "(" && prior[stk.back()] >= prior[t]) {
                    ans.push_back(stk.back());
                    stk.pop_back();
                }
                stk.push_back(t);
            } else { // digit
                ans.push_back(t);
            }
        }
        
        while (!stk.empty()) {
            ans.push_back(stk.back());
            stk.pop_back();
        }
        return ans;
    }
    
    int calc() {
        if (prior.count(post_expr[ptr])) {
            const string& opt = post_expr[ptr];
            ptr--;
            const int rhs = calc();
            const int lhs = calc();
            
            if (opt == "+") {
                return lhs + rhs;
            } else if (opt == "-") {
                return lhs - rhs;
            } else if (opt == "*") {
                return lhs * rhs;
            } else { // if (opt == "/")
                return lhs / rhs;
            }
        } else {
            return stoi(post_expr[ptr--]);
        }
    }
};