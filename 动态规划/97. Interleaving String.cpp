class Solution {
public:
    bool dfs(vector<vector<int>>& dp, const string& s1, const string& s2, const string& s3, int ptr1, int ptr2) {
        const int ptr3 = ptr1 + ptr2;

        if (ptr3 == s3.size()) {
            return ptr1 == s1.size() && ptr2 == s2.size();
        }
        if (ptr1 == s1.size()) {
            return dp[ptr1][ptr2] = s2.substr(ptr2) == s3.substr(ptr3);
        }
        if (ptr2 == s2.size()) {
            return dp[ptr1][ptr2] = s1.substr(ptr1) == s3.substr(ptr3);
        }

        if (dp[ptr1][ptr2] != -1) {
            return dp[ptr1][ptr2];
        }

        if (s1[ptr1] == s3[ptr3] && s2[ptr2] == s3[ptr3]) {
            return dp[ptr1][ptr2] = dfs(dp, s1, s2, s3, ptr1 + 1, ptr2) || dfs(dp, s1, s2, s3, ptr1, ptr2 + 1);
        } else if (s1[ptr1] == s3[ptr3] && s2[ptr2] != s3[ptr3]) {
            return dp[ptr1][ptr2] = dfs(dp, s1, s2, s3, ptr1 + 1, ptr2);
        } else if (s1[ptr1] != s3[ptr3] && s2[ptr2] == s3[ptr3]) {
            return dp[ptr1][ptr2] = dfs(dp, s1, s2, s3, ptr1, ptr2 + 1);
        } else {
            return dp[ptr1][ptr2] = false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 5, vector<int>(s2.size() + 5, -1));
        return dfs(dp, s1, s2, s3, 0, 0);
    }
};