class Solution {
public:
    string clearDigits(string s) {
        string ans;

        for (const char ch : s) {
            if (is_digit(ch)) {
                ans.pop_back();
            } else {
                ans += ch;
            }
        }
        return ans;
    }
private:
    bool is_digit(const char ch) {
        return '0' <= ch && ch <= '9';
    }
};