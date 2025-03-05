class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int n = s.size();
        vector<int> f(n + 1, 0);
        for (const auto& shift : shifts) {
            const int start = shift[0];
            const int end = shift[1];
            const int dir = shift[2];

            const int delta = dir == 1 ? 1 : -1;
            f[start] += delta;
            f[end + 1] -= delta;
        }

        for (int i = 1; i <= n; i++) {
            f[i] += f[i - 1];
        }

        for (int i = 0; i < n; i++) {
            const int val = s[i] - 'a';
            const int next_val = ((val + f[i]) % 26 + 26) % 26;
            s[i] = 'a' + next_val;
        }
        return s;
    }
};