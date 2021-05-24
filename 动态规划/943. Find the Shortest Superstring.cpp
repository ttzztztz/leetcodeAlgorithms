class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        this->words = words;
        n = words.size();
        
        memset(connect, 0, sizeof connect);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            connect[i][j] = 0;
            for (int k = min(words[i].size(), words[j].size()) - 1; k >= 0; k--) {
                if (suffix(words[i], k) == prefix(words[j], k)) {
                    connect[i][j] = k;
                    break;
                }
            }
        }
        
        string ans;
        for (int i = 0; i < n; i++) {
            string t = words[i] + dfs(i, 1 << i);
            if (ans.empty() || t.size() < ans.size()) ans = t;
        }
        return ans;
    }
private:
    int connect[12][12];
    string f[12][1 << 12];
    int n;
    vector<string> words;
    
    string prefix(const string& str, int i) {
        return str.substr(0, i);
    }
    
    string suffix(const string& str, int i) {
        return str.substr(str.size() - i);
    }
    
    string dfs(int i, int state) {
        if (state == (1 << n) - 1) return "";
        string& val = f[i][state];
        if (!val.empty()) return val;
        
        string cur;
        for (int j = 0; j < n; j++) {
            if (state & (1 << j)) continue;
            
            string t = suffix(words[j], words[j].size() - connect[i][j]) + dfs(j, state | (1 << j));
            if (cur.empty() || t.size() < cur.size()) cur = t;
        }
        return val = cur;
    }
};