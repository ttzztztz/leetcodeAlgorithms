class Solution {
public:
    /**
     * @param str: the string you wanna print.
     * @return: return the minimum times you need to hit the keyboard.
     */
    int minimumTyping(string &str) {
        memset(f, 0xff, sizeof f);
        return dfs(str, 0, 0);
    }
private:
    int f[100005][2];
    int dfs(const string& str, int i, int state) {
        if (i == str.size()) return state == 1 ? 1 : 0;
        int& val = f[i][state];
        if (val != -1) return val;
        
        int answer = 9999999;
        const bool isUpper = str[i] >= 'A' && str[i] <= 'Z';
        if (isUpper) {
            if (state == 1) {
                answer = min(answer, 1 + dfs(str, i + 1, state));
            } else {
                answer = min(answer, 2 + dfs(str, i + 1, state));
                answer = min(answer, 2 + dfs(str, i + 1, state ^ 1));
            }
        } else {
            if (state == 0) {
                answer = min(answer, 1 + dfs(str, i + 1, state));
            } else {
                answer = min(answer, 2 + dfs(str, i + 1, state));
                answer = min(answer, 2 + dfs(str, i + 1, state ^ 1));
            }
        }
        
        return val = answer;
    }
};
