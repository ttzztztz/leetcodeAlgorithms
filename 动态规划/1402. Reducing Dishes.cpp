class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        const int N = satisfaction.size();
        f = vector<vector<int>>(N + 5, vector<int>(N + 5, -1));
        
        return dfs(satisfaction, 0, 1);
    }
private:
    vector<vector<int>> f;
    int dfs(const vector<int>& satisfaction, int i, int t) {
        if (i == satisfaction.size()) return 0;
        if (f[i][t] != -1) return f[i][t];
        
        int answer = 0;
        
        answer = max(answer, satisfaction[i] * t + dfs(satisfaction, i + 1, t + 1));
        answer = max(answer, dfs(satisfaction, i + 1, t));
        
        return f[i][t] = answer;
    }
};
