class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, pair<int, string>> memo;
        
        const int Q = indexes.size();
        for (int i = 0; i < Q; i++) {
            if (S.substr(indexes[i], sources[i].size()) == sources[i]) {
                memo[indexes[i]] = {sources[i].size(), targets[i]};
            }
        }
        
        string answer;
        for (int i = 0; i < S.size(); ) {
            if (memo.count(i)) {
                int origin_len;
                string new_str;
                tie(origin_len, new_str) = memo[i];
                
                answer += new_str;
                i += origin_len;
            } else {
                answer.push_back(S[i]);
                i++;
            }
        }
        return answer;
    }
};