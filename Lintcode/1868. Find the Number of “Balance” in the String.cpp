class Solution {
public:
    /**
     * @param S: the string
     * @return: return the number of “Balance” in the string
     */
    int find(string &S) {
        const int N = S.size();
        unordered_map<char, int> windowLeft, windowRight;
        for (const char ch : S) windowRight[ch]++;
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            windowLeft[S[i]]++;
            windowRight[S[i]]--;
            if (windowRight[S[i]] == 0) windowRight.erase(S[i]);
            if (windowLeft.size() == windowRight.size()) answer++;
        }
        
        return answer;
    }
};
