class Solution {
public:
    bool judge(const string& sub, const string& super) {
        if (sub.size() + 1 == super.size()) {
            bool used = false;
            int ptr1 = 0, ptr2 = 0;
            while (ptr2 < super.size()) {
                if (ptr1 < sub.size() && sub[ptr1] == super[ptr2]) {
                    ptr1++, ptr2++;
                } else {
                    if (used) {
                        return false;
                    }

                    ptr2++;
                    used = true;
                }
            }

            return true;
        } else {
            return false;
        }
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& $1, const string& $2)->bool{
            return $1.size() < $2.size();
        });
        const int N = words.size();
        vector<int> dp(N + 5, 1);
        int answer = 1;

        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (words[j].size() + 1 > words[i].size()) {
                    continue;
                } else if (words[j].size() + 1 < words[i].size()) {
                    break;
                }

                if (judge(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                answer = max(answer, dp[i]);
            }
        }

        return answer;
    }
};