class Solution {
public:
    int calculate(string s) {
        const int n = s.size();
        char last_op = '+';
        typedef long long ll;

        ll ans = 0, last = 0, buf = 0;
        for (int i = 0; i < s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') buf = buf * 10 + s[i] - '0';

            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
                if (last_op == '+') {
                    ans = ans + buf;
                    last = buf;
                } else if (last_op == '-') {
                    ans = ans - buf;
                    last = -buf;
                } else if (last_op == '*') {
                    ans = ans - last + last * buf;
                    last = last * buf;
                } else if (last_op == '/') {
                    ans = ans - last + last / buf;
                    last = last / buf;
                }

                if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                    last_op = s[i];
                    buf = 0;
                }
            }
        }
        return ans;
    }
};