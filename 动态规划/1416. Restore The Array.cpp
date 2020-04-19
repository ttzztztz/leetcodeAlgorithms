class Solution {
public:
    int numberOfArrays(string s, int k) {
        memset(f, 0xff, sizeof f);
        return dfs(0, s, k);
    }
private:
    const int MOD = 1e9 + 7;
    long long f[100005];
    long long dfs(int i, const string& s, const int k) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (f[i] != -1) return f[i];
        
        long long answer = 0;
        long long d = 0;
        for (int j = i; j < s.size(); j++) {
            d *= 10;
            d += s[j] - '0';
            
            if (d > k) break;
            answer += dfs(j + 1, s, k);
            answer %= MOD;
        }
        
        return f[i] = answer;
    }
};
