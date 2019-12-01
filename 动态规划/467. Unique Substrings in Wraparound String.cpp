class Solution {
public:
    char prevChar(char ch) {
        ch--;
        if (ch < 'a') {
            ch = 'z';
        }
        return ch;
    }
    int findSubstringInWraproundString(string p) {
        int answer = 0;
        vector<int> dp(26, 0);

        for (int i = 0; i < p.size(); i++) {
            int right = i;

            while (right + 1 < p.size() && p[right] == prevChar(p[right + 1])) {
                right++;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], right - i + 1);
        }

        for (int i = 0; i < 26; i++) {
            answer += dp[i];
        }
        return answer;
    }
};