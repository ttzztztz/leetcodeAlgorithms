class Solution {
public:
    string init(string &s) {
        string result = "$";
        for (int i = 0; i < s.size(); i++) {
            result.push_back(s[i]);
            result.push_back('#');
        }
        return result;
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        string targetString = init(s);

        int dp[targetString.size() + 5];
        std::memset(dp, 0, sizeof(dp));

        int len = targetString.size();
        int center = 0, right = 0;
        int resultCenter = 0, resultAnswer = 0;
        for (int i = 1; i < len; i++) {
            int radius = 1;

            if (right >= i) {
                radius = std::min(dp[2 * center - i], right - i);
            }

            while (targetString[i + radius] == targetString[i - radius]) {
                radius++;
            }

            if (i + radius > right) {
                center = i;
                right = i + radius;
            }

            dp[i] = radius;
            if (radius - 1 > resultAnswer) {
                resultAnswer = radius - 1;
                resultCenter = center;
            }
        }

        string result = "";
        for (int i = resultCenter - resultAnswer; i <= resultCenter + resultAnswer; i++) {
            if (targetString[i] != '#') {
                result.push_back(targetString[i]);
            }
        }
        return result;
    }
};