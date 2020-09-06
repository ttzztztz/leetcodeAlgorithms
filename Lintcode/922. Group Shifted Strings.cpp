class Solution {
public:
    /**
     * @param strings: a string array
     * @return: return a list of string array
     */
    vector<vector<string>> groupStrings(vector<string> &strings) {
        vector<vector<string>> answer;
        const int N = strings.size();
        vector<string> process = strings;
        for (string& s : process) {
            if (s[0] == 'a') continue;
            
            const int d = s[0] - 'a';
            for (char& ch : s) {
                ch -= d;
                if (ch < 'a') ch += 26;
            }
        }
        
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            vector<string> cur{strings[i]};
            for (int j = 0; j < N; j++) {
                if (visited[j]) continue;
                if (process[i] == process[j]) {
                    visited[j] = true;
                    cur.push_back(strings[j]);
                }
            }
            answer.push_back(cur);
        }
        
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                answer.push_back(vector<string>{strings[i]});
            }
        }
        return answer;
    }
};
