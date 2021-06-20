class Solution {
public:
    string largestOddNumber(string num) {
        const int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            const int d = num[i] - '0';
            if (d % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
