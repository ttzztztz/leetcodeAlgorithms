class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int a = 0, b = 0;
        
        typedef pair<int, int> PII;
        vector<PII> all;
        const int n = aliceValues.size();
        for (int i = 0; i < n; i++) all.emplace_back(aliceValues[i], bobValues[i]);
        
        sort(all.begin(), all.end(), [](const auto& $1, const auto& $2) -> bool {
            if ($1.first + $1.second == $2.first + $2.second) return $1.first > $2.first;
            return $1.first + $1.second > $2.first + $2.second;
        });
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) a += all[i].first;
            else b += all[i].second;
        }
        
        if (a > b) return 1;
        else if (a < b) return -1;
        else return 0;
    }
};
