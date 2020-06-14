class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        memset(f, 0xff, sizeof f);
        memset(cost, 0, sizeof f);
        
        for (int i = 0; i < houses.size(); i++) {
            for (int j = i + 1; j < houses.size(); j++) {
                for (int t = i; t <= j; t++) {
                    cost[i][j] += abs(houses[(i + j) / 2] - houses[t]);
                }
            }
        }

        return dfs(houses, 0, k);
    }
private:
    vector<int> d, pref;
    int m;
    int f[105][105];
    int cost[105][105];
    const int MAX = 100000;
    int dfs(const vector<int>& houses, int i, int k) {
        if (k < 0) return MAX;
        if (i == houses.size()) return k == 0 ? 0 : MAX;
        int& val = f[i][k];
        if (val != -1) return val;
        
        int answer = MAX;
        for (int a = i; a < houses.size(); a++) {
            answer = min(answer, cost[i][a] + dfs(houses, a + 1, k - 1));
        }
        return val = answer;
    }
};
