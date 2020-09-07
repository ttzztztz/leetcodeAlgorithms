class Solution {
public:
    /**
     * @param s: a string.
     * @return: return the values of all the intervals.
     */
    long long suffixQuery(string &s) {
        memset(f, 0xff, sizeof f);
        this->s = s;
        this->n = s.size();
        
        long long answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                answer += dfs(i, j);
            }
        }
        return answer;
    }
private:
    long long f[3005][3005];
    int n;
    string s;
    
    long long dfs(int i, int j) {
        if (i == j) return 1;
        if (i > j) return 0;
        long long& val = f[i][j];
        if (val != -1) return val;
        
        long long answer = 0;
        if (s[i] == s[j]) {
            if (dfs(i + 1, j - 1) == j - i - 1) answer += 2 + dfs(i + 1, j - 1);
            else answer += 1 + dfs(i + 1, j - 1);
        }
        return val = answer;
    }
};
