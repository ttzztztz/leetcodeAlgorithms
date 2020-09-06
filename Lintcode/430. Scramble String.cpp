class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        // write your code here
        unordered_map<char, int> a1, a2;
        for (const char ch : s1) a1[ch]++;
        for (const char ch : s2) a2[ch]++;
        memset(f, 0xff, sizeof f);
        
        if (a1 != a2) return false;
        n = s1.size(), m = s2.size();
        this->s1 = s1, this->s2 = s2;
        
        return dfs(n, 0, 0);
    }
private:
    int n, m;
    string s1, s2;
    
    int f[105][105][105];
    int dfs(int n, int i, int j) {
        if (n < 0) return false;
        if (n == 0) return true;
        if (n == 1) return s1[i] == s2[j];
        
        int& val = f[n][i][j];
        if (val != -1) return val;
        
        int answer = 0;
        const int a = i, b = i + n - 1;
        const int c = j, d = j + n - 1;
        
        // x + k - 1 = j + n - 1
        // x = j + n - k
        
        // x + n - k - 1 = i + n - 1
        // x = i + k
        for (int k = 1; k < n; k++) {
            answer |= dfs(k, i, j) & dfs(n - k, i + k, j + k);
        }
        for (int k = 1; k < n; k++) {
            answer |= dfs(k, i, j + n - k) & dfs(n - k, i + k, j);
        }
        return val = answer;
    }
};
