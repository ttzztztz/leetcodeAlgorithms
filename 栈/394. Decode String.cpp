class Solution {
public:
    string decodeString(string s) {
        string buf;
        vector<int> stk;
        vector<string> ans = { "" };
        const int n = s.size();

        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'z') {
                ans.back() += s[i];
            } else if ('0' <= s[i] && s[i] <= '9') {
                buf += s[i];
            } else if (s[i] == '[') {
                stk.push_back(stoi(buf));
                ans.push_back("");
                buf.clear();
            } else if (s[i] == ']') {
                const int repeat_cnt = stk.back();
                stk.pop_back();

                const string repeat_str = ans.back();
                ans.pop_back();

                for (int i = 0; i < repeat_cnt; i++) {
                    ans.back() += repeat_str;
                }
            }
        }

        string res;
        for (const string& s : ans) res += s;
        return res;
    }
};