class Solution {
public:
    /**
     * @param words: the words given.
     * @param wordA: the first word you need to find.
     * @param wordB: the second word you need to find.
     * @return: return the spacing of the closest wordA and wordB.
     */
    int wordSpacing(vector<string> &words, string &wordA, string &wordB) {
        const int N = words.size();
        int answer = N + 5;
        
        vector<int> v1, v2;
        for (int i = 0; i < N; i++) {
            const string& word = words[i];
            if (word == wordA) {
                v1.push_back(i);
            } else if (word == wordB) {
                v2.push_back(i);
            }
        }
        
        for (int i = 0; i < v1.size(); i++) {
            const int n = v1[i];
            auto it = lower_bound(v2.begin(), v2.end(), n);
            
            if (it != v2.end()) {
                answer = min(answer, (int) abs(n - *it));
            }
            
            if (it != v2.begin()) {
                it--;
                answer = min(answer, (int) abs(n - *it));
            }
        }
        
        if (answer == N + 5) return -1;
        return answer;
    }
};
