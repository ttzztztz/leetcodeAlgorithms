class Solution {
public:
    /**
     * @param target: a target string 
     * @param dictionary: a set of strings in a dictionary
     * @return: an abbreviation of the target string with the smallest possible length
     */
    string minAbbreviation(string &target, vector<string> &dictionary) {
        const int N = target.size(), mask = (1 << N) - 1;
        
        unordered_set<int> maskSet;
        for (const string& s : dictionary) {
            if (s.size() != target.size()) continue;
            maskSet.insert(getMask(target, s));
        }
        
        string answer;
        for (int state = 1; state <= mask; state++) {
            bool valid = true;
            for (int j : maskSet) {
                if ((state & j) == state) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            
            string cur = generate(state, target);
            if (answer.empty() || cur.size() < answer.size()) answer = cur;
        }
        return answer;
    }
private:
    int getMask(const string& target, const string& word) {
        int answer = 0;
        const int N = target.size();
        for (int i = 0; i < N; i++) {
            if (target[i] == word[i]) answer |= 1 << i;
        }
        return answer;
    }
    string generate(const int mask, const string& target) {
        string answer;
        int cnt0 = 0;
        for (int i = 0; i < target.size(); i++) {
            if (mask & (1 << i)) {
                if (cnt0 > 0) {
                    answer += to_string(cnt0);
                    cnt0 = 0;
                }
                answer += target[i];
            } else {
                cnt0++;
            }
        }
        if (cnt0 > 0) answer += to_string(cnt0);
        return answer;
    }
};
