#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[1000][1000];
    string s1, s2;
    int len1, len2;

    int min3(int $1, int $2, int $3) {
        return std::min(std::min($1, $2), $3);
    }

    int DP(int offset1, int offset2) {
        if (offset1 < 0 || offset2 < 0) {
            return 0;
        }

        if (offset1 >= len1 && offset2 >= len2) {
            return 0;
        } else if (offset1 >= len1 && offset2 < len2) {
            return len2 - offset2;
        } else if (offset2 >= len2 && offset1 < len1) {
            return len1 - offset1;
        }

        if (this->dp[offset1][offset2]) {
            return this->dp[offset1][offset2];
        }

        int answer = 0;

        if (s1[offset1] == s2[offset2]) {
            answer = DP(offset1 + 1, offset2 + 1);
        } else {
            answer = this->min3(
                    this->DP(offset1 + 1, offset2) + 1,
                    this->DP(offset1, offset2 + 1) + 1,
                    this->DP(offset1 + 1, offset2 + 1) + 1
            );
        }

        return this->dp[offset1][offset2] = answer;
    }

    int minDistance(string word1, string word2) {
        memset(this->dp, 0, sizeof(this->dp));
        this->s1 = std::move(word1);
        this->s2 = std::move(word2);
        this->len1 = this->s1.length();
        this->len2 = this->s2.length();
        return this->DP(0, 0);
    }
};

int main() {

    return 0;
}