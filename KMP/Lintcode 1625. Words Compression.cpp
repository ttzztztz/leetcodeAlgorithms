class Solution {
public:
    /**
     * @param s: the given strings
     * @return: Output the first occurrence of each string in `s` in the target compression string.
     */
    vector<int> wordsCompression(vector<string> &s) {
        const int N = s.size();
        vector<int> answer(N, 0);
        total = s[0];
        
        for (int i = 1; i < N; i++) {
            int overwrite, firstAppear;
            tie(overwrite, firstAppear) = kmp(s[i]);
            
            if (firstAppear == -1) firstAppear = total.size() - overwrite;
            answer[i] = firstAppear;
            total += s[i].substr(overwrite);
        }
        return answer;
    }
private:
    string total;
    pair<int, int> kmp(const string& str) {
        int firstAppear = -1;
        
        const int M = str.size();
        vector<int> nxt(M + 1, 0);
        nxt[0] = -1;
        int i = 1, j = 0;
        while (i < M) {
            if (str[i] == str[j] || j == -1) {
                nxt[++i] = ++j;
            } else {
                j = nxt[j];
            }
        }
        
        i = 0, j = 0;
        const int N = total.size();
        while (i < N) {
            if (total[i] == str[j] || j == -1) {
                i++, j++;
            } else {
                j = nxt[j];
            }
            
            if (j == M) {
                if (firstAppear == -1) firstAppear = i - M;
                if (i == N) {
                    return {j, firstAppear};
                } else {
                    j = nxt[j];
                }
            }
            
            if (i == N) {
                return {j, firstAppear};
            }
        }
        
        return {0, N - 1};
    }
};
