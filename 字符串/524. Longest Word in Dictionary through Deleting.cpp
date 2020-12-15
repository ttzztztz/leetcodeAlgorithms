class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if (s.empty()) return "";

        string ans;
        for (const string& str : d) {
            if (judge(str, s)) {
                if (ans == "" || str.size() > ans.size() || (str.size() == ans.size() && str < ans)) {
                    ans = str;
                }
            }
        }
        return ans;
    }
private:
    bool judge(const string& str, const string& s) {
        // delete some char in s , st. s==str
        for (int i = 0, j = 0; i < str.size(); i++, j++) {
            while (j < s.size() && str[i] != s[j]) j++;
            if (j == s.size() || str[i] != s[j]) return false;
        }
        return true;
    }
};
