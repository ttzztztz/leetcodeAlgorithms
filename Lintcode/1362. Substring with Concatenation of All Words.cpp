class Solution {
public:
    /**
     * @param s: a string
     * @param words: a list of words
     * @return: all starting indices of substring(s)
     */
    vector<int> findSubstring(string &s, vector<string> &words) {
        vector<int> ans;
        const int n = s.size(), m = words.size(), k = words[0].size();
        vector<int> finalState;
        unordered_map<string, int> app;
        for (int i = 0, cnt = 0; i < m; i++) {
            if (app.count(words[i])) {
                finalState[app[words[i]]]++;
            } else {
                app[words[i]] = cnt;
                cnt++;
                finalState.push_back(1);
            }
        }
        
        for (int l = 0, r = k * m - 1; r < n; l++, r++) {
            vector<int> visited(finalState.size(), 0);
            
            bool valid = true;
            int ptr = l;
            for (int i = 0; i < m; i++) {
                string tmp;
                for (int j = 0; j < k; j++) {
                    tmp += s[ptr++];
                }
                
                if (app.count(tmp)) visited[app[tmp]]++;
                else {
                    valid = false;
                    break;
                }
                
                if (visited[app[tmp]] > finalState[app[tmp]]) {
                    valid = false;
                    break;
                }
            }
            
            if (!valid) continue;
            if (visited == finalState) {
                ans.push_back(l);
            }
        }
        
        return ans;
    }
};
