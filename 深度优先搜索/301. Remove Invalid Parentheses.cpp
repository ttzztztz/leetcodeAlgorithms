class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        string cur;
        dfs(s, cur, 0, 0, min_remove(s));
        return vector<string>(ans.begin(), ans.end());
    }
private:
    unordered_set<string> ans;

    int min_remove(const string& s) {
        int ans = 0, balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance++;
            } else if (s[i] == ')') {
                if (balance >= 1) balance--;
                else ans++;
            }
        }
        return ans + balance;
    }

    void dfs(const string& s, string& cur, int idx, int balance, int rest_removal) {
        if (idx == s.size()) {
            if (balance == 0) ans.insert(cur);
            return;
        }

        if (s[idx] != '(' && s[idx] != ')') {
            cur.push_back(s[idx]);
            dfs(s, cur, idx + 1, balance, rest_removal);
            cur.pop_back();
            return;
        }

        if (s[idx] == '(') {
            cur += '(';
            dfs(s, cur, idx + 1, balance + 1, rest_removal);
            cur.pop_back();

            if (rest_removal >= 1) dfs(s, cur, idx + 1, balance, rest_removal - 1);
        } else if (s[idx] == ')') {
            if (balance >= 1) {
                cur += ')';
                dfs(s, cur, idx + 1, balance - 1, rest_removal);
                cur.pop_back();
            }

            if (rest_removal >= 1) dfs(s, cur, idx + 1, balance, rest_removal - 1);
        }
    }
};