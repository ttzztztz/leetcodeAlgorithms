class Solution {
private:
    string abbreviation(const string& raw, const int prefix) {
        if (prefix >= raw.size() - 2) {
            return raw;
        }
        
        string answer;
        for (int i = 0; i < prefix; i++) answer += raw[i];
        answer += to_string(raw.size() - 1 - prefix);
        answer += raw[raw.size() - 1];
        return answer;
    }
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        vector<string> answer = dict;
        const int N = answer.size();
        vector<int> prefixLen(N, 1);
        
        for (int i = 0; i < N; i++) {
            const string& s = answer[i];
            if (s.size() <= 3) continue;
            answer[i] = abbreviation(dict[i], 1);
        }
        
        for (int i = 0; i < N; i++) {
            while (true) {
                unordered_set<int> nxt;
                for (int j = i + 1; j < N; j++) {
                    if (answer[i] == answer[j]) {
                        nxt.insert(j);
                    }
                }
                
                if (nxt.empty()) break;
                nxt.insert(i);
                for (int v : nxt) {
                    prefixLen[v]++;
                    answer[v] = abbreviation(dict[v], prefixLen[v]);
                }
            }
        }
        
        return answer;
    }
};
