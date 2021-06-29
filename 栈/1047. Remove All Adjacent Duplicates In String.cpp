class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            const char t = s[i];
            bool insert = true;
            while (!ans.empty() && ans.back() == t) insert = false, ans.pop_back();
            if (insert) ans += t;
        }
        return ans;
    }
};