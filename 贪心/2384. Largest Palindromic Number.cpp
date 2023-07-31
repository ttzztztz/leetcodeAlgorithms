class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> appear(10, 0);
        for (const char& ch : num) appear[ch - '0']++;
        int max_odd = -1;
        for (int i = 9; i >= 0; i--) {
            if (appear[i] % 2 == 0) continue;

            if (max_odd == -1) max_odd = i;
            else appear[i]--;
        }

        string first_half;
        for (int i = 9; i >= 0; i--) {
            if (i == 0 && first_half.empty()) continue;
            const char ch = '0' + i;

            // for odd, eg 7 / 2 = 3
            for (int k = 0; k < appear[i] / 2; k++) first_half += ch;
        }
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        string ans;
        if (max_odd == -1) {
            // even
            ans = first_half + second_half;
        } else {
            // odd
            const char middle_char = '0' + max_odd;
            ans = first_half + middle_char + second_half;
        }

        if (ans.empty()) return "0";
        return ans;
    }
};