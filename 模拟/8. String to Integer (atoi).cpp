class Solution {
public:
    int myAtoi(string s) {
        const int n = s.size();

        int startIndex = 0;
        while (startIndex < n && s[startIndex] == ' ') startIndex++;

        int sign = 0;
        const int sign_pos = 1, sign_neg = -1, sign_invalid = 0;
        
        long long buf = 0;
        bool have_digit = false;
        int int_max = numeric_limits<int>::max(), int_min = numeric_limits<int>::min();

        for (int i = startIndex; i < n; i++) {
            const char ch = s[i];

            if (s[i] == '+' || s[i] == '-') {
                if (sign != sign_invalid || have_digit) return get_number(sign, buf);

                if (s[i] == '+') sign = sign_pos;
                else sign = sign_neg;
            } else if ('0' <= s[i] && s[i] <= '9') {
                buf = buf * 10 + (s[i] - '0');

                const long long val = get_number(sign, buf);
                if (val > int_max) return int_max;
                if (val < int_min) return int_min;

                have_digit = true;
            } else {
                return get_number(sign, buf);
            }
        }

        return get_number(sign, buf);
    }
private:
    long long get_number(int sign, long long buf) {
        const bool positive = (sign == 0 || sign == 1);
        return positive ? buf : -buf;
    }
};