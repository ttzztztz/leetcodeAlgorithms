class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        // write your code here
        this->p = pattern, this->s = str;
        return dfs(0, 0);
    }
private:
    unordered_map<char, string> f;
    unordered_map<string, char> g;
    string p, s;

    bool dfs(int i, int j) {
        if (i == p.size()) return j == s.size();
        if (j == s.size()) return 0;
        
        if (f.count(p[i])) {
            string str = f[p[i]];
            const int len = str.size();
            if (s.substr(j, len) == str) {
                return dfs(i + 1, j + len);
            }
        } else {
            for (int k = j; k < s.size(); k++) {
                string ss = s.substr(j, k - j + 1);
                if (g.count(ss)) continue;
                
                f[p[i]] = ss;
                g[ss] = p[i];
                if (dfs(i + 1, k + 1)) return true;
                f.erase(p[i]);
                g.erase(ss);
            }
        }
        return false;
    }
};
