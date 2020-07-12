class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9+7;
        const int N = s.size();

        long long answer = 0;
        
        for (int l = 0, r = 0; r < N; r++) {
            if (s[r] == '1') {
                answer += r - l + 1;
                answer %= MOD;
            } else {
                l = r + 1;
            }
        }
        
        return answer;
    }
};