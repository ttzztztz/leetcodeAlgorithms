class Solution {
public:
    bool checkZeroOnes(string s) {
        return check(s, '1') > check(s, '0');
    }
private:
    int check(const string& str, char ch) {
        int ans = 0, cur = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ch) {
                cur++;
            } else {
                cur = 0;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
