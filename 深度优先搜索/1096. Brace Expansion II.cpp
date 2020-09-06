class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> ans = dfs(expression);
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    vector<string> dfs(const string& str) {        
        if (str.empty()) return vector<string>{};
        if (str.size() == 1) return vector<string>{string(str[0], 1)};
        
        unordered_set<string> cur;
        vector<vector<string>> tmp = {{""}};
        const vector<vector<string>> initTmp = {{""}};
        int level = 0, start = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '{') {
                level++;
                if (level == 1) start = i;
            } else if (str[i] == '}') {
                level--;
                if (level == 0) {
                    tmp.emplace_back(dfs(str.substr(start + 1, i - start - 1)));
                    tmp.emplace_back(vector<string>{""});
                }
            } else if (str[i] == ',') {
                if (level == 0) {
                    vector<string> finalAnswer = process(tmp);
                    for (const string& s : finalAnswer) {
                        cur.insert(s);
                    }
                    tmp = initTmp;
                }
            } else {
                if (level == 0) {
                    tmp[tmp.size() - 1][0] += str[i];
                }
            }
        }
        
        if (tmp != initTmp) {
            vector<string> finalAnswer = process(tmp);
            for (const string& s : finalAnswer) {
                cur.insert(s);
            }
        }
        
        return vector<string>(cur.begin(), cur.end());
    }
    vector<string> process(vector<vector<string>>& src) {
        vector<string> answer;
        string tmp;
        dfs(src, answer, tmp, 0);
        return answer;
    }
    void dfs(const vector<vector<string>>& src, vector<string>& answer, string& tmp, int i) {
        if (i == src.size()) {
            if (!tmp.empty()) answer.push_back(tmp);
            return;
        }
        for (int k = 0; k < src[i].size(); k++) {
            const int len = src[i][k].size();
            
            tmp += src[i][k];
            dfs(src, answer, tmp, i + 1);
            
            for (int s = 0; s < len; s++) tmp.pop_back();
        }
    }
};
