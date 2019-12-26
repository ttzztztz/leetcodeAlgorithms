#include <iostream>
#include <cstring>

using namespace std;

string s1, s2;
int dp[8005][8005];

int dfs(int i, int j) {
    const int N = s1.size(), M = s2.size();

    if (i == N && j == M) {
        return 1;
    }
    if (i >= N) {
        int answer = 1;
        for (; j < M; j++) {
            if (s2[j] != '*') {
                answer = 0;
                break;
            }
        }
        return answer;
    }

    if (j >= M) {
        int answer = 1;
        for (; i < N; i++) {
            if (s1[i] != '*') {
                answer = 0;
                break;
            }
        }
        return answer;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int answer = 0;
    if (s1[i] == s2[j]) {
        answer |= dfs(i + 1, j + 1);
    }
    if (s1[i] == '*') {
        answer |= dfs(i + 1, j);
        answer |= dfs(i + 1, j + 1);
    }
    if (s2[j] == '*') {
        answer |= dfs(i, j + 1);
        answer |= dfs(i + 1, j + 1);
    }
    return dp[i][j] = answer;
}

int main() {
    int T = 0;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        s1.clear(), s2.clear();

        string temp;
        cin >> temp;
        for (const char ch : temp) {
            if (ch == '*') {
                for (int k = 0; k < 4; k++) {
                    s1.push_back('*');
                }
            } else {
                s1.push_back(ch);
            }
        }

        temp.clear();
        cin >> temp;
        for (const char ch : temp) {
            if (ch == '*') {
                for (int k = 0; k < 4; k++) {
                    s2.push_back('*');
                }
            } else {
                s2.push_back(ch);
            }
        }

        memset(dp, 0xff, sizeof(dp));
        printf("Case #%d: %s \n", _,
               dfs(0, 0) ? "TRUE" : "FALSE");
    }
    return 0;
}
