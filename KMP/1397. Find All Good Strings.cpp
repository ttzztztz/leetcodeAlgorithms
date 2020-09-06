const int MAX = 505;
const int MOD = 1e9+7;

class Solution {
public:
    long long dp[MAX][2][MAX];
    int digestArr[MAX], digestLen = 0;

    long long dfs(int length, int isSmall, int state) {
        if (state == evil.size()) {
            return 0;
        }

        if (length == 0) {
            return 1;
        }

        if (dp[length][isSmall][state] != -1) {
            return dp[length][isSmall][state];
        }

        long long answer = 0;
        for (int i = 0; i <= 25; i++) {
            if (!isSmall && i > digestArr[length]) {
                break;
            }

            if (i == evil[state] - 'a') {
                answer += dfs(
                        length - 1,
                        isSmall || i < digestArr[length],
                        state + 1
                );
            } else {
                int j = state;

                while (j > 0 && i != evil[j] - 'a') {
                    j = nxt[j];
                }

                if (j == -1 || evil[j] - 'a' == i) {
                    j++;
                }

                answer += dfs(
                        length - 1,
                        isSmall || i < digestArr[length],
                        j
                );
            }

            answer %= MOD;
        }

        return dp[length][isSmall][state] = answer;
    }

    long long solve(const string& s) {
        std::memset(dp, 0xff, sizeof(dp));
        std::memset(digestArr, 0, sizeof(digestArr));

        const int N = s.size();
        digestLen = 0;
        for (int i = N - 1; i >= 0; i--) {
            digestArr[++digestLen] = s[i] - 'a';
        }

        return dfs(digestLen, 0, 0);
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        if (s1 > s2) return 0;

        this->evil = evil;
        buildkmp();

        long long answer2 = solve(s2);
        long long answer1 = solve(s1);

        long long tmp = (((answer2 - answer1) % MOD) + MOD) % MOD;
        if (s1.find(evil) == string::npos) tmp++;
        tmp %= MOD;

        return tmp;
    }
private:
    string evil;
    vector<int> nxt;
    void buildkmp() {
        const string& s = evil;

        const int N = s.size();
        nxt = vector<int>(N + 1, 0);
        nxt[0] = -1, nxt[1] = 0;

        int i = 1, j = 0;
        while (i < N) {
            if (j == -1 || s[i] == s[j]) {
                nxt[++i] = ++j;
            } else {
                j = nxt[j];
            }
        }
    }
};
