class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const int N = str1.size(), M = str2.size();
        vector<vector<int>> dp(N + 2, vector<int>(M + 2, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string answer;
        int ptr1 = N, ptr2 = M;
        while (ptr1 >= 1 && ptr2 >= 1) {
            if (str1[ptr1 - 1] == str2[ptr2 - 1]) {
                answer.push_back(str1[ptr1 - 1]);
                ptr1--;
                ptr2--;
            } else if (dp[ptr1][ptr2] == dp[ptr1][ptr2 - 1]) {
                answer.push_back(str2[ptr2 - 1]);
                ptr2--;
            } else if (dp[ptr1][ptr2] == dp[ptr1 - 1][ptr2]) {
                answer.push_back(str1[ptr1 - 1]);
                ptr1--;
            }
        }
        while (ptr1 >= 1) {
            answer.push_back(str1[ptr1 - 1]);
            ptr1--;
        }
        while (ptr2 >= 1) {
            answer.push_back(str2[ptr2 - 1]);
            ptr2--;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};