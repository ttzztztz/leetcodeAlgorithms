class Solution {
public:
    int minimumDistance(string word) {
        const int n = word.size();
        vector<vector<int>> f(27, vector<int>(27, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> g(27, vector<int>(27, numeric_limits<int>::max()));
            const int d = word[i] - 'A';
            for (int a = 0; a <= 26; a++) for (int b = 0; b <= 26; b++) {
                int cost1 = 0, cost2 = 0;
                if (a != 26) cost1 = dist(point('A' + a), point(word[i]));
                if (b != 26) cost2 = dist(point('A' + b), point(word[i]));
                g[a][b] = min(f[d][b] + cost1, f[a][d] + cost2);
            }
            f = g;
        }
        
        return f[26][26];
    }
private:
    typedef pair<int, int> PII;
    PII point(char ch) {
        const int d = ch - 'A';
        return { d / 6, d % 6 };
    }
    int dist(const PII& lhs, const PII& rhs) {
        auto [x1, y1] = lhs;
        auto [x2, y2] = rhs;
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
