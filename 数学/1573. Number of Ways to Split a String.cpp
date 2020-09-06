class Solution {
public:
    const int mod = 1e9+7;
    int numWays(string s) {
        const int n = s.size();
        
        int cnt1 = 0;
        vector<int> all1;
        for (int i = 0; i < n; i++) {
            const char c = s[i];
            if (c == '1') {
                cnt1++;
                all1.push_back(i);
            }
        }
        
        if (cnt1 == 0) return C(n - 1, 2);
        if (cnt1 % 3 != 0) return 0;
        const int part = cnt1 / 3;
        const int v1 = all1[part] - all1[part - 1];
        const int v2 = all1[part * 2] - all1[part * 2 - 1];
        
        return (1ll * v1 * v2) % mod;
    }
private:
    long long fastPow(long long a, int b) {
        long long answer = 1, base = a;
        while (b) {
            if (b & 1) {
                answer *= base;
                answer %= mod;
            }
            
            base *= base;
            base %= mod;
            b >>= 1;
        }
        return answer;
    }
    long long frac(int n) {
        long long answer = 1;
        for (int i = 2; i <= n; i++) {
            answer = (answer * i) % mod;
        }
        return answer;
    }
    long long C(int n, int m) {
        long long answer = frac(n) * fastPow(frac(m), mod - 2);
        answer %= mod;
        answer *= fastPow(frac(n - m), mod - 2);
        answer %= mod;
        return answer;
    }
};
