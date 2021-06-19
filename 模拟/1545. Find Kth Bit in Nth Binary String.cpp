class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            s = s + "1" + reverse(invert(s));
        }
        return s[k - 1];
    }
private:
    string invert(const string& str) {
        string ans;
        for (int i = 0; i < str.size(); i++) ans += (str[i] == '1' ? '0' : '1');
        return ans;
    }
    string reverse(const string& str) {
        string ans;
        for (int i = str.size() - 1; i >= 0; i--) ans += str[i];
        return ans;
    }
};