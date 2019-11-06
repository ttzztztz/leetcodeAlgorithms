class Solution {
public:
    int len_ring, len_key, dp[105][105];
    int dfs(const string& ring, const string& key, int ringPtr, int keyPtr) {
        if (keyPtr == len_key) {
            return 0;
        }
        if (dp[ringPtr][keyPtr] != -1) {
            return dp[ringPtr][keyPtr];
        }

        int answer = 9999999;
        if (key[keyPtr] == ring[ringPtr]) {
            answer = min(answer, dfs(ring, key, ringPtr, keyPtr + 1) + 1);
        } else {
            for (int i = 0; i < len_ring; i++) {
                if (ring[i] == key[keyPtr]) {
                    answer = min(answer, dfs(ring, key, i, keyPtr + 1) + min(abs(i - ringPtr), len_ring - abs(i - ringPtr)) + 1);
                }
            }
        }
        return dp[ringPtr][keyPtr] = answer;
    }
    int findRotateSteps(string ring, string key) {
        len_ring = ring.size(), len_key = key.size();
        memset(dp, 0xff, sizeof(dp));

        return dfs(ring, key, 0, 0);
    }
};