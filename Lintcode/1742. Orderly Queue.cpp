class Solution {
public:
    /**
     * @param S: a string
     * @param K: int
     * @return: the lexicographically smallest string
     */
    string orderlyQueue(string &S, int K) {
        if (K >= 2) {
            sort(S.begin(), S.end());
            return S;
        } else {
            string ans = S;
            const int n = S.size();
            for (int i = 0; i < n; i++) {
                const char ch = S[0];
                S.erase(S.begin());
                S.push_back(ch);
                
                ans = min(ans, S);
            }
            return ans;
        }
    }
};
