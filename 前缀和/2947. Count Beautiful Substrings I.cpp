class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        const int n = s.size();
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + is_vowel(s[i - 1]);
        }

        int ans = 0;
        for (int r = 0; r <= n; r++) {
            for (int l = 0; l < r; l++) {
                const int v = f[r] - f[l];
                const int c = r - l - v;

                if (v == c && (v * c) % k == 0) ans++;
            }
        }
        return ans;
    }
private:
    int is_vowel(const char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};