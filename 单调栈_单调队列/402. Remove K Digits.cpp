class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !ans.empty() && ans.back() > num[i]) {
                k--;
                ans.pop_back();
            }

            ans += num[i];
        }

        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        int leading_zero_cnt = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '0') {
                leading_zero_cnt++;
            } else {
                break;
            }
        }
        
        string final_ans = ans.substr(leading_zero_cnt);
        if (final_ans.empty()) return "0";
        return final_ans;
    }
};