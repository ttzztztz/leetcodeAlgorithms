class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        const int n = properties.size();
        sort(properties.begin(), properties.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
            else return lhs[0] < rhs[0];
        });
        
        set<int> s;
        for (int i = n - 1; i >= 0; i--) {
            const int d = properties[i][1];
            if (s.upper_bound(d) != s.end()) ans++;
            s.insert(d);
        }
        
        return ans;
    }
};