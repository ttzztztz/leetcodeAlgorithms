class Solution {
public:
    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        if (s.empty()) return 0;
        this->s = s;
        this->n = s.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(0);
    }
private:
    string s;
    int n;
    long long f[100005];
    const int mod = 1e9+7;
    
    long long dfs(int i) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        long long& val = f[i];
        if (val != -1) return val;
        long long answer = 0;
        
        if (i + 1 < n && (s[i] == '1' || s[i] == '2')) {
            string x = {s[i]};
            if (s[i + 1] != '*') {
                x.push_back(s[i + 1]);
                const int d = stoi(x);
                if (d >= 1 && d <= 26) answer += dfs(i + 2);
            } else {
                if (s[i] == '1') answer += 9 * dfs(i + 2);
                else if (s[i] == '2') answer += 6 * dfs(i + 2);
            }
        }
        
        if (s[i] == '*') {
            answer += 9 * dfs(i + 1);
            
            if (i + 1 < n) {
                if (s[i + 1] == '*') {
                    answer += 15 * dfs(i + 2);
                } else {
                    if (s[i + 1] >= '7') {
                        answer += dfs(i + 2);
                    } else {
                        answer += 2 * dfs(i + 2);
                    }
                }
            }
        } else {
            answer += dfs(i + 1);
        }
        
        answer %= mod;
        return val = answer;
    }
};
