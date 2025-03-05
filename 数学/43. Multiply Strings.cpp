class Solution {
public:
    string multiply(string num1, string num2) {
        const int len1 = num1.size(), len2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> ans(len1 + len2 + 1, 0);
        for (int i = 0; i < len1; i++) for (int j = 0; j < len2; j++) {
            ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            ans[i + j + 1] += ans[i + j] / 10;
            ans[i + j] %= 10;
        }

        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        string ans_str;
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans_str += '0' + ans[i];
        }
        return ans_str;
    }
};