class Solution {
public:
    /**
     * @param s: 
     * @return: the minimum number of turns the printer needed in order to print it
     */
    int strangePrinter(string &s) {
        memset(f, 0xff, sizeof f);
        this->n = s.size();
        this->s = s;
        return dfs(0, n - 1);
    }
private:
    int f[105][105];
    int n;
    string s;
    
    int dfs(int i, int j) {
        if (i == j) return 1;
        if (i > j) return 0;
        
        int& val = f[i][j];
        if (val != -1) return val;
        
        int answer = 1 + dfs(i + 1, j);
        for (int k = i + 1; k <= j; k++) {
            if (s[i] == s[k]) {
                answer = min(answer, dfs(i + 1, k) + dfs(k + 1, j));
            }
        }
        return val = answer;
    }
};