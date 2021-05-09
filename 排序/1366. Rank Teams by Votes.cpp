class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";
        const int n = votes.size(), m = votes[0].size();
        unordered_map<char, vector<int>> data;
        for (const string& vote : votes) {
            for (int j = 0; j < m; j++) {
                if (!data.count(vote[j])) data[vote[j]] = vector<int>(m, 0);
                data[vote[j]][j]++;
            }
        }
        
        vector<vector<int>> sorted_data;
        for (auto [k, v] : data) {
            v.push_back(k);
            sorted_data.push_back(v);
        }
        sort(sorted_data.begin(), sorted_data.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            for (int i = 0; i < m; i++) {
                if (lhs[i] != rhs[i]) {
                    return lhs[i] > rhs[i];
                }
            }
            return lhs[m] < rhs[m];
        });
        
        string ans;
        for (int i = 0; i < m; i++) ans += (char) sorted_data[i].back();
        return ans;
    }
};