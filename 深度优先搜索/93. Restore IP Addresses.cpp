class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return answer;
        dfs(s, 0, 0);
        return answer;
    }
private:
    vector<string> answer;
    string tmp;
    void dfs(const string& s, int cur, int seg) {
        if (cur == s.size()) {
            if (seg == 4) answer.push_back(tmp);
            return;
        }
        string f;
        for (int i = cur; i < min(cur + 3, int(s.size())); i++) {
            if (i == cur + 1 && s[cur] == '0') return;
            
            f.push_back(s[i]);
            const int d = stoi(f);
            if (d >= 0 && d <= 255) {
                tmp += f;
                if (seg != 3) tmp += '.';
                dfs(s, i + 1, seg + 1);
                if (seg != 3) tmp.pop_back();
                for (int _ = 0; _ < f.size(); _++) tmp.pop_back();
            }
        }
    }
};
