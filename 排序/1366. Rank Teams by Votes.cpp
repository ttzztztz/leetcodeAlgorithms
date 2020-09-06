class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int N = votes.size(), M = votes[0].size();
        unordered_set<char> allChars, used;
        
        vector<vector<int>> pre(M, vector<int>(26, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                pre[j][votes[i][j] - 'A']++;
                allChars.insert(votes[i][j]);
            }
        }
        
        string answer;
        while (used.size() < allChars.size()) {
            unordered_set<char> tmp;
            for (char i : allChars) {
                if (!used.count(i)) {
                    tmp.insert(i);
                }
            }
            
            int j = 0;
            while (tmp.size() >= 2) {
                if (j >= M) break;
                
                vector<int> statics(26, 0);
                for (int i = 0; i < 26; i++) {
                    if (used.count(i + 'A') || !tmp.count(i + 'A')) continue;
                    statics[i] += pre[j][i];
                }

                int maxVal = 0;
                vector<char> nxt;
                for (int i = 0; i < 26; i++) {
                    if (used.count(i + 'A') || !tmp.count(i + 'A')) continue;
                    if (statics[i] > maxVal) {
                        nxt = vector<char>{i + 'A'};
                        maxVal = statics[i];
                    } else if (statics[i] == maxVal) {
                        nxt.push_back(i + 'A');
                    }
                }
                
                if (!nxt.empty()) tmp = unordered_set<char>(nxt.begin(), nxt.end());
                if (nxt.size() == 1) break;
                j++;
            }
            
            vector<char> candidate;
            for (char p : tmp) candidate.push_back(p);
            sort(candidate.begin(), candidate.end());
            answer.push_back(candidate[0]);
            used.insert(candidate[0]);
        }
        
        return answer;
    }
};
