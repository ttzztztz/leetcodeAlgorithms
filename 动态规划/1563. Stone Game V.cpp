class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        memset(pref, 0, sizeof pref);
        memset(f, 0xff, sizeof f);
        n = stoneValue.size();
        s = stoneValue;
        
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + s[i - 1];
        return dfs(1, n);
    }
private:
    int pref[505], n;
    int f[505][505];
    vector<int> s;
    int dfs(int i, int j) {
        if (i == j) return 0;
        int& val = f[i][j];
        if (val != -1) return val;
        
        int answer = 0;
        for (int k = i; k + 1 <= j; k++) {
            const int a = pref[k] - pref[i - 1], b = pref[j] - pref[k];
            if (a < b) {
                answer = max(answer, a + dfs(i, k));
            } else if (a > b) {
                answer = max(answer, b + dfs(k + 1, j));
            } else {
                answer = max(answer, max(a + dfs(i, k), b + dfs(k + 1, j)));
            }
        }
        return val = answer;
    }
};
