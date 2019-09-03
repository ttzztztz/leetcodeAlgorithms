#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    return 0;
}