class Solution {
public:
    /**
     * @param s: the long string
     * @param word: the secrect word
     * @return: whether a substring exists in the string can be transformed by the above encoding rule
     */
    string getAns(string &s, string &word) {
        const int N = s.size(), M = word.size();
        
        for (int i = 0; i + M - 1 < N; i++) {
            const int j = i + M - 1;
            if (judge(s, word, i, j)) return "yes";
        }
        return "no";
    }
private:
    bool judge(const string &s, const string &word, int start, int end) {
        unordered_map<char, char> mapOldToNew;
        unordered_set<char> used;
        
        for (int i = start; i <= end; i++) {
            const int offset = i - start;
            if (!mapOldToNew.count(word[offset])) {
                mapOldToNew[word[offset]] = s[i];
                if (used.count(s[i])) return false;
                used.insert(s[i]);
            }
            
            if (mapOldToNew[word[offset]] != s[i]) return false;
        }
        return true;
    }
};
