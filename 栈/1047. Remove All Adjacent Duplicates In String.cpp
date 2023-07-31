class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (const char& ch : s) {
            bool poped = false;
            while (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
                poped = true;
            }
            if (!poped) ans += ch;
        }
        return ans;
    }
};