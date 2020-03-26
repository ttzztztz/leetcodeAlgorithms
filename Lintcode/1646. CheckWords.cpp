class Solution {
public:
    /**
     * @param s: 
     * @param str: 
     * @return: Output whether this combination meets the condition
     */
    bool checkWord(string &s, vector<string> &str) {
        valid = unordered_set<string>(str.begin(), str.end());
        return dfs(s);
    }
private:
    unordered_set<string> valid;
    bool dfs(const string& s) {
        if (!valid.count(s)) return false;
        if (s.size() == 1) return true;
        
        for (int i = 0; i < s.size(); i++) {
            string tmp = s;
            tmp.erase(tmp.begin() + i);
            if (valid.count(tmp) && dfs(tmp)) return true;
        }
        
        return false;
    }
};
