class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && stk.back() == pair<char, int>{ s[i], k - 1 }) {
                for (int i = 0; i < k - 1; i++) stk.pop_back();
                continue;
            }

            if (stk.empty()) {
                stk.emplace_back(s[i], 1);
                continue;
            }

            stk.emplace_back(s[i], s[i] == stk.back().first ? stk.back().second + 1 : 1);
        }

        string ans;
        for (auto [ch, _] : stk) ans += ch;
        return ans;
    }
};