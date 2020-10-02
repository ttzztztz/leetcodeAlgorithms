class Solution {
public:
    /**
     * @param S: a string
     * @return: the sum of UNIQ(substring) over all non-empty substrings of S
     */
    int uniqueLetterString(string &S) {
        // Write your code here
        unordered_map<char, vector<int>> appear;
        const int n = S.size();
        for (int i = 0; i < n; i++) appear[S[i]].push_back(i);
        
        long long answer = 0;
        const int mod = 1e9+7;
        for (auto& p : appear) {
            const vector<int>& v = p.second;
            
            for (int prev = -1, idx = 0; idx < v.size(); prev = v[idx], idx++) {
                const int l = v[idx] - prev;
                const int r = (idx + 1 >= v.size()) ? (n - v[idx]) : (v[idx + 1] - v[idx]);
                
                answer = (answer + (1ll * l * r)) % mod;
            }
        }
        
        return answer;
    }
};
