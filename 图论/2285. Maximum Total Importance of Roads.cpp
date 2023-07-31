class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for (const auto& road : roads) {
            deg[road[0]]++;
            deg[road[1]]++;
        }
        sort(deg.begin(), deg.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs > rhs;
        });
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1ll * (n - i) * deg[i];
        }
        return ans;
    }
};
