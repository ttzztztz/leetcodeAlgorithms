class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        for (int i = 1; i <= 9; i++) dfs(i, N - 1, K);
        if (N == 1) answer.push_back(0);
        return answer;
    }
private:
    vector<int> answer;

    void dfs(int state, int N, const int K) {
        if (N == 0) {
            answer.push_back(state);
            return;
        }
        
        const int last = state % 10;
        const int d1 = last + K, d2 = last - K;
        if (d1 >= 0 && d1 <= 9) dfs(state * 10 + d1, N - 1, K);
        if (d2 >= 0 && d2 <= 9 && d2 != d1) dfs(state * 10 + d2, N - 1, K);
    }
};
