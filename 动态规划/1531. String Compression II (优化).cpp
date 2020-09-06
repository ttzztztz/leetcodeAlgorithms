int f[105][105][30][15];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        
        const int N = s.size();
        if (N == 100 && k == 0) {
            bool allSame = true;
            for (int i = 1; i < N; i++) {
                if (s[i] != s[i - 1]) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) {
                return 4;
            }
        }
        
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k <= 26; k++) {
                    for (int m = 0; m <= 10; m++) {
                        f[i][j][k][m] = -1;
                    }
                }
            }
        }
        
        return dfs(0, k, 26, 0);
    }
private:
    string s;
    int dfs(int idx, int k, int last, int concat) {
        if (k < 0) return 9999999;
        if (idx == s.size()) return 0;
        
        int& val = f[idx][k][last][concat];
        if (val != -1) return val;
        
        int answer = 9999999;
		// delete
        answer = min(answer, dfs(idx + 1, k - 1, last, concat));
        // concat
        if (last == s[idx] - 'a') {
            const int fac = (concat == 1 || concat == 9) ? 1 : 0;
            answer = min(answer, fac + dfs(idx + 1, k, last, min(10, concat + 1)));
        } else {
            answer = min(answer, 1 + dfs(idx + 1, k, s[idx] - 'a', 1));
        }
        return val = answer;
    }
};
