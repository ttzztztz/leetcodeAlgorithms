class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        N = hats.size();
        
        hatOfPeople = vector<vector<int>>(45, vector<int>{});
        f = vector<vector<int>>((1 << N) + 5, vector<int>(45, -1));
        
        for (int i = 0; i < hats.size(); i++) {
            for (int j = 0; j < hats[i].size(); j++) {
                hatOfPeople[hats[i][j]].push_back(i);
            }
        }
        
        return dfs(0, 0);
    }
private:
    int N;
    vector<vector<int>> hatOfPeople;
    vector<vector<int>> f;
    long long dfs(int state, int hat) {
        const int endState = (1 << N) - 1;
        if (state == endState) return 1;
        if (hat >= 41) return 0;
        if (f[state][hat] != -1) return f[state][hat];
        const int MOD = 1e9+7;
        
        long long answer = 0;
        answer += dfs(state, hat + 1);
        answer %= MOD;
        
        for (int j : hatOfPeople[hat]) {
            if (!(state & (1 << j))) {
                answer += dfs(state | (1 << j), hat + 1);
                answer %= MOD;
            }
        }
        return f[state][hat] = answer;
    }
};
