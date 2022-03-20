class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        alice = aliceArrows;
        ans = cur = vector<int>(12, 0);
        dfs(numArrows, 0, 0);
        
        const int t = accumulate(ans.begin(), ans.end(), 0);
        const int rest = numArrows - t;
        for (int i = 0; i < 12; i++) {
            if (ans[i] > alice[i]) {
                ans[i] += rest;
                break;
            }
        }
        return ans;
    }
private:
    vector<int> alice, ans, cur;
    int max_score = 0;
    void dfs(int rest, int round, int current_score) {
        if (round >= 12) {
            if (current_score > max_score) {
                max_score = current_score;
                ans = cur;
            }
            return;
        }
        
        cur[round] = 0;
        dfs(rest, round + 1, current_score);
        if (rest >= alice[round] + 1) {
            cur[round] = alice[round] + 1;
            dfs(rest - alice[round] - 1, round + 1, current_score + round);
        }
    }
};
