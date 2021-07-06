class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        typedef pair<int, int> PII;
        vector<PII> all;
        for (int i = 0; i < n; i++) all.emplace_back(scores[i], ages[i]);
        sort(all.begin(), all.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            if (lhs.second == rhs.second) return lhs.first < rhs.first;
            return lhs.second < rhs.second;
        });
        
        vector<int> f(1002);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> g(1002);
            for (int j = 0; j <= 1001; j++) {
                if (j != 1001 && j >= ages.size()) continue;
                
                g[j] = f[j];
                const int max_score = (j == 1001) ? -1 : all[j].first;
                if (all[i].first >= max_score) g[j] = max(g[j], all[i].first + f[i]);
            }
            f = move(g);
        }
        return f[1001];
    }
};