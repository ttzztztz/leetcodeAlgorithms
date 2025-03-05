class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string val = countAndSay(n - 1);
        const int m = val.size();

        string ans;
        for (int i = 0; i < m; i++) {
            const char ch = val[i];

            int repeat = 1;
            while (i + 1 < m && val[i] == val[i + 1]) {
                repeat++;
                i++;
            }

            ans += to_string(repeat) + ch;
        }
        return ans;
    }
};