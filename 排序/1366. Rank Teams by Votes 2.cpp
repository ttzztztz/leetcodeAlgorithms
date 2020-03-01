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
        for (char i : allChars) answer.push_back(i);
        sort(answer.begin(), answer.end(), [&](const char $1, const char $2)->bool {
            for (int i = 0; i < M; i++) {
                if (pre[i][$1 - 'A'] != pre[i][$2 - 'A']) return pre[i][$1 - 'A'] > pre[i][$2 - 'A'];
            }
            return $1 < $2;
        });
        return answer;
    }
};
