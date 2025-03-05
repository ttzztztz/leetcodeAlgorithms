class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(s, cur, 0);
        return ans;
    }
private:
    vector<vector<string>> ans;

    bool is_palindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    void dfs(const string& s, vector<string>& cur, int idx) {
        if (idx == s.size()) {
            ans.push_back(cur);
            return;
        }

        string t;
        for (int j = idx; j < s.size(); j++) {
            t += s[j];
            if (is_palindrome(t)) {
                cur.push_back(t);
                dfs(s, cur, j + 1);
                cur.pop_back();
            }
        }
    }
};