class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        const int MAX = 0x6f6f6f6f, maxState = (1 << target.size()) - 1;

        int dp[maxState + 5];
        std::memset(dp, 0x6f, sizeof(dp));
        dp[0] = 0;

        for (int i = 0; i <= maxState; i++) {
            if (dp[i] == MAX) {
                continue;
            }

            for (const string& sticker : stickers) {
                int nextState = i;
                for (int k = 0; k < sticker.size(); k++) {
                    const char ch = sticker[k];
                    for (int j = 0; j < target.size(); j++) {
                        if (target[j] == ch && (nextState & (1 << j)) == 0) {
                            nextState |= (1 << j);
                            break;
                        }
                    }
                }

                dp[nextState] = std::min(dp[nextState], dp[i] + 1);
            }
        }
        return dp[maxState] == MAX ? -1 : dp[maxState];
    }
};