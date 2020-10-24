class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        const int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        for (int i = 0, j = n - 1, cur = P, pts = 0; i < n && i <= j;) {
            if (cur - tokens[i] >= 0) {
                cur -= tokens[i];
                i++, pts++;
            } else {
                if (pts > 0) {
                    pts--;
                    cur += tokens[j];
                    j--;
                } else break;
            }
            
            ans = max(ans, pts);
        }
        return ans;
    }
};
