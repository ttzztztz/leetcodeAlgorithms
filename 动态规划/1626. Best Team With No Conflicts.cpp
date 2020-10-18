class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        typedef pair<int, int> PII;
        vector<PII> player;
        const int n = scores.size();
        
        for (int i = 0; i < n; i++) player.emplace_back(scores[i], ages[i]);
        sort(player.begin(), player.end(), [&](const auto& $1, const auto& $2) -> bool {
            if ($1.second == $2.second) return $1.first < $2.first;
            return $1.second < $2.second;
        });
        
        vector<int> f(1005, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            f[i] = player[i].first;
            for (int j = 0; j < i; j++) {
                if ((player[i].second == player[j].second && player[j].first <= player[i].first) || (player[i].second > player[j].second && player[i].first >= player[j].first)) {
                    f[i] = max(f[i], f[j] + player[i].first);
                }
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
