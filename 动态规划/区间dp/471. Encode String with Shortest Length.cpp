class Solution {
public:
    string encode(string s) {
        const int n = s.size();
        string f[n + 1][n + 1];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                f[i][j] = s.substr(i, len);

                for (int k = i; k + 1 <= j; k++) {
                    if (f[i][j].size() > (f[i][k] + f[k + 1][j]).size()) {
                        f[i][j] = f[i][k] + f[k + 1][j];
                    }
                }
                
                auto [compress_len, repeat] = can_compress(s.substr(i, len));
                string tmp = to_string(repeat) + "[" + f[i][i + compress_len - 1] + "]";
                if (tmp.size() < f[i][j].size()) f[i][j] = tmp;
            }
        }
        return f[0][n - 1];
    }
private:
    typedef pair<int, int> PII;
    PII can_compress(const string& s) {
        string t = s + s;
        const int len = t.find(s, 1);
        return { len, s.size() / len };
    }
};