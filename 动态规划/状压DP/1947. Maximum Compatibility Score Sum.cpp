class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size(), m = students[0].size();
        ca = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            ca[i][j] = diff(students[i], mentors[j]);
        }
        
        memset(f, 0xff, sizeof f);
        return dfs(0, 0);
    }
private:
    int n, m;
    vector<vector<int>> ca;
    int f[9][512];
    
    int diff(const vector<int>& lhs, const vector<int>& rhs) {
        int ans = 0;
        for (int i = 0; i < m; i++) ans += (lhs[i] == rhs[i]);
        return ans;
    }
    
    int dfs(int idx, int mentor) {
        int& val = f[idx][mentor];
        if (val != -1) return val;
        
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (mentor & (1 << j)) continue;
            ans = max(ans, ca[idx][j] + dfs(idx + 1, mentor | (1 << j)));
        }
        return val = ans;
    }
};