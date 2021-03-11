class Solution {
public:
    string intToRoman(int num) {
        string ans;
        vector<pair<int, string>> rule = {
            {   1, "I" },
            {   4, "IV"},
            {   5, "V" },
            {   9, "IX"},
            {  10, "X" },
            {  40, "XL"},
            {  50, "L" },
            {  90, "XC"},
            { 100, "C" },
            { 400, "CD"},
            { 500, "D" },
            { 900, "CM"},
            {1000, "M" }
        };
        
        const int n = rule.size();
        while (num) {
            for (int i = n - 1; i >= 0; i--) {
                if (num >= rule[i].first) {
                    ans += rule[i].second;
                    num -= rule[i].first;
                    break;
                }
            }
        }
        return ans;
    }
};
